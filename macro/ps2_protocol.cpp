
#include "ps2_protocol.h"

#include "ps2_debug.h"

// A bit of a hack to change states.
#define NEXT_STATE(s) \
      static_cast<State>(static_cast<int>(s) + 1)

const int PS2Protocol::kBufferSize = PS2Protocol::kBufferArraySize - 1;

PS2Protocol::PS2Protocol(IsrHandler isr_handler)
    : clock_pulses_(0),
      isr_handler_(isr_handler),
      debug_(0),
      clock_pin_(NOT_A_PIN),
      data_pin_(NOT_A_PIN),
      head_(0),
      tail_(0),
      state_(WAIT_R_START),
      current_(0),
      parity_(HIGH) {
}

PS2Protocol::~PS2Protocol() {
  end();
}

bool PS2Protocol::begin(uint8_t clock_pin, uint8_t data_pin, PS2Debug* debug) {
  if (clock_pin == data_pin)
    return false;

  int isr = digitalPinToInterrupt(clock_pin);
  if (isr == NOT_AN_INTERRUPT)
    return false;

  if (clock_pin_ != NOT_A_PIN || data_pin_ != NOT_A_PIN)
    return false;

  clock_pin_ = clock_pin;
  data_pin_ = data_pin;
  pinMode(clock_pin_, INPUT_PULLUP);
  pinMode(data_pin_, INPUT_PULLUP);
  attachInterrupt(isr, isr_handler_, FALLING);

  debug_ = debug;
  return true;
}

int PS2Protocol::available() {
  int count = (head_ - tail_ + kBufferArraySize) % kBufferArraySize;
  if (debug_)
    debug_->recordProtocolAvailable(count);
  return count;
}

byte PS2Protocol::read() {
  // Extract the byte at |tail_| before incrementing it to prevent races.
  byte b = buffer_[tail_];
  tail_  = (tail_ + 1) % kBufferArraySize;
  return b;
}

void PS2Protocol::write(byte b) {
  // Acquire the clock and data lines and put them into "request-to-send" state.
  // This means holding the clock and data low for 100usec, then releasing the
  // clock.
  //
  // Interrupts are detached while setting the clock and data lines so that
  // a spurious interrupt is not geneated by the lowering clock line.
  // Without this PS2Procotol, which is likely in the state WAIT_R_START,
  // will generates an "invalid start bit" error as the clock falls.
  detachInterrupt(digitalPinToInterrupt(clock_pin_));
  pinMode(clock_pin_, OUTPUT);
  pinMode(data_pin_, OUTPUT);
  digitalWrite(clock_pin_, LOW);
  digitalWrite(data_pin_, LOW);
  delayMicroseconds(100);
  attachInterrupt(digitalPinToInterrupt(clock_pin_), isr_handler_, FALLING);

  // At this point, the PS2 device will have detected the request-to-send and
  // will stop generating the clock.  The member variables normally touched
  // only by the ISR can be set.
  state_ = WAIT_S_DATA0;
  current_ = b;
  parity_ = HIGH;

  // Now relese the clock so that the device can start generating it again.
  pinMode(clock_pin_, INPUT_PULLUP);
}

bool PS2Protocol::writeAndWait(byte b) {
  write(b);

  // Wait until the byte has been sent and then return.  Ih theory, the device
  // may take up to 15msec to start generating the clock.  Once started, the
  // transfer should not take more than 2msec.
  while (state_ > WAIT_R_IGNORE)
    delay(6);

  // TODO: may want to return false if it took more than 17msec.
  // TODO: add some histograms to see how long this actually takes.
  return true;
}

void PS2Protocol::end() {
  if (clock_pin_ == NOT_A_PIN)
    return;

  detachInterrupt(digitalPinToInterrupt(clock_pin_));
  clock_pulses_ = 0;
  debug_ = 0;
  clock_pin_ = NOT_A_PIN;
  data_pin_ = NOT_A_PIN;
  head_ = 0;
  tail_ = 0;
  state_ = WAIT_R_START;
  current_ = 0;
  parity_ = HIGH;
}

void PS2Protocol::callIsrHandlerForTesting(int bit) {
  if (state_ < WAIT_S_DATA0) {
    isrHandleReceivedBit(bit);
  } else {
    isrHandleSendBit(bit);
  }
}

void PS2Protocol::isrHandlerImpl() {
  ++clock_pulses_;

  if (state_ < WAIT_S_DATA0) {
    isrHandleReceivedBit(digitalRead(data_pin_));
  } else {
    int bit = state_ == WAIT_S_ACK ? digitalRead(data_pin_) : LOW;
    isrHandleSendBit(bit);
  }
}

void PS2Protocol::isrHandleReceivedBit(int bit) {
  switch(state_) {
    case WAIT_R_START:
      // The start bit should always be zero.
      if (!bit) {
        state_ = WAIT_R_DATA0;
        current_ = 0;
        parity_ = HIGH;
      } else {
        handleError(F("Invalid start bit"));
      }
      break;
    case WAIT_R_DATA0:
    case WAIT_R_DATA1:
    case WAIT_R_DATA2:
    case WAIT_R_DATA3:
    case WAIT_R_DATA4:
    case WAIT_R_DATA5:
    case WAIT_R_DATA6:
    case WAIT_R_DATA7: {
      current_ >>= 1;
      if (bit) {
        current_ |= 0x80;
        parity_ = parity_ == HIGH ? LOW : HIGH;
      }

      state_ = NEXT_STATE(state_);
      break;
    }
    case WAIT_R_PARITY:
      // Parity is expected to be odd, so the read bit should equal the
      // accumulated parity.
      if (bit != parity_) {
        handleError(F("Invalid parity bit"));
        break;
      }
      state_ = WAIT_R_STOP;
      break;
    case WAIT_R_STOP:
      // The stop bit should always be one.
      if (bit) {
        byte new_head = (head_ + 1) % kBufferArraySize;
        // If the buffer is not full, add the currently accumulated byte.
        if (new_head != tail_) {
          buffer_[head_] = current_;
          head_  = new_head;
        } else {
          handleError(F("Protocol buffer overflow"));
          break;
        }
      } else {
        handleError(F("Invalid stop bit"));
        break;
      }
      state_ = WAIT_R_START;
      break;
    case WAIT_R_IGNORE:
      break;
    default:
      handleError(F("Invalid PS2 state"));
      break;
  }
}

void PS2Protocol::isrHandleSendBit(int bit) {
  switch(state_) {
    case WAIT_S_DATA0:
    case WAIT_S_DATA1:
    case WAIT_S_DATA2:
    case WAIT_S_DATA3:
    case WAIT_S_DATA4:
    case WAIT_S_DATA5:
    case WAIT_S_DATA6:
    case WAIT_S_DATA7: {
      byte sbit = (current_ & 1) ? HIGH : LOW;
      current_ >>= 1;
      if (sbit)
        parity_ = parity_ == HIGH ? LOW : HIGH;

      digitalWrite(data_pin_, sbit);
      state_ = NEXT_STATE(state_);
      break;
    }
    case WAIT_S_PARITY:
      digitalWrite(data_pin_, parity_);
      state_ = WAIT_S_STOP;
      break;
    case WAIT_S_STOP:
      pinMode(data_pin_, INPUT_PULLUP);
      state_ = WAIT_S_ACK;
      break;
    case WAIT_S_ACK:
      // ACK bit should always be a zero.
      if (bit) {
        handleError(F("Invalid ACK"));
        break;
      }

      state_ = WAIT_R_START;
      break;
    default:
      handleError(F("Invalid PS2 state"));
      break;
  }
}

void PS2Protocol::handleError(const __FlashStringHelper* error) {
  if (error && debug_)
    debug_->ErrorHandler(error);

  state_ = WAIT_R_START;
  // TODO: send a "re-send" (0xFE) command to device?
}
