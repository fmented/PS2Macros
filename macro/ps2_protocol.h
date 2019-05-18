#ifndef PS2_PROTOCOL_H_
#define PS2_PROTOCOL_H_

#include <Arduino.h>

// Missing definition in 1.0.6.
#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT -1
#endif

class PS2Debug;

/**
 * Class to handle low level PS2 keyboard/mouse protocol.
 *
 * Because ISR handlers do not take an argument, it is not possible to support
 * multiple instances of this class without specifying a unique handler for
 * each instance.  To help with this, use the following special macros.
 *
 * To declare a global variable of type PS2Protocol use the PS2P_GLOBAL macro.
 * For example:
 *
 *     #include "ps2_protocol.h"
 *
 *     PSP2_GLOBAL(protocol);
 *
 *     void setup() {
 *       protocol.begin(2, 3);
 *     }
 *
 *     void loop() {
 *       while (protocol.available() > 0) {
 *         byte b = protocol.read();
 *         // Do something with byte.
 *       }
 *     }
 *
 * To declare a class member variable of type PS2Protocol use the
 * PS2P_DECLARE macro in the class declaration, and then PSP2_IMPLEMENT in the
 * cpp file.  It is important that the arguments used with both macros match.
 * For example:
 *
 *  In sample.h:
 *
 *     #include "ps2_protocol.h"
 *
 *     class Sample {
 *      public:
 *       Sample() {}
 *       begin();
 *       // ...
 *      private:
 *       PSP2_DECLARE(Sample, protocol_);
 *     };
 *
 *  In sample.cpp:
 *
 *     PS2P_IMPLEMENT(Sample, protocol_);
 *
 *     Sample::begin() {
 *       protocol_.begin(2, 3);
 *     }
 */
class PS2Protocol {
 public:
  // Number of bytes received from PS2 device that will be buffered by
  // PS2Protocol.  If the buffer overflows, newer bytes will be dropped.
  const static int kBufferSize;

  // An ISR handler for this instance of PS2 protocol.
  typedef void (*IsrHandler)();

  // Normally called via the macros.
  PS2Protocol(IsrHandler isr_handler);
  ~PS2Protocol();

  // Initialize the PS2 protocol object.  This is normally called once from the
  // setup() function.  |clock_pin| must be a pin that supports interrupts.
  // |data_pin| can be any digital pin.
  //
  // Returns true if the PS2 protocol object is initialized correctly, and
  // false otherwise.
  bool begin(uint8_t clock_pin, uint8_t data_pin, PS2Debug* debug=0);

  // Returns the number of bytes available for reading.
  int available();

  // Reads the next available byte.  Should only be called if available()
  // returns greated than zero.
  byte read();

  // Sends one byte to the PS2 device.  This function returns immediately and
  // does not wait for the byte to be sent.
  void write(byte b);

  // Similar to the write() method, but waits for the byte to be sent before
  // returning.
  bool writeAndWait(byte b);

  // Disable the PS2 protocol object.  The clock and data pins can now be
  // used for other purposes.
  void end();

  // ISR handler.  Not called directly, should only be called from the
  // PSP2_IMPLEMENT macro.
  void isrHandlerImpl();

  // Used only for testing.  |bit| should be either LOW or HIGH only.
  void callIsrHandlerForTesting(int bit);

  // States while receiving a byte from the PS device or sending a byte to the
  // PS device.  States with R_ are used when receiving, and states with S_
  // are used when sending.
  //
  // The code assumes that R_ and S_ states are consecutive integers in the
  // order given.  It also assumes that the R_ states are smaller than the S_
  // states.  These states are for internal use only, and are made public
  // here only for testing purposes.
  enum State {
    // States used while receiving a byte from the PS2 device.
    WAIT_R_START,  // Waiting for start bit, always 0, initial state
    WAIT_R_DATA0,  // Waiting for bit 0 of byte
    WAIT_R_DATA1,  // Waiting for bit 1 of byte
    WAIT_R_DATA2,  // Waiting for bit 2 of byte
    WAIT_R_DATA3,  // Waiting for bit 3 of byte
    WAIT_R_DATA4,  // Waiting for bit 4 of byte
    WAIT_R_DATA5,  // Waiting for bit 5 of byte
    WAIT_R_DATA6,  // Waiting for bit 6 of byte
    WAIT_R_DATA7,  // Waiting for bit 7 of byte
    WAIT_R_PARITY,  // Waiting for (odd) parity bit
    WAIT_R_STOP,  // Waiting for stop bit, always 1
    WAIT_R_IGNORE,  // Ignore any bits sent from device

    // States used while sending a byte to the PS2 device.
    WAIT_S_DATA0,  // Waiting to write bit 0 of byte
    WAIT_S_DATA1,  // Waiting to write bit 1 of byte
    WAIT_S_DATA2,  // Waiting to write bit 2 of byte
    WAIT_S_DATA3,  // Waiting to write bit 3 of byte
    WAIT_S_DATA4,  // Waiting to write bit 4 of byte
    WAIT_S_DATA5,  // Waiting to write bit 5 of byte
    WAIT_S_DATA6,  // Waiting to write bit 6 of byte
    WAIT_S_DATA7,  // Waiting to write bit 7 of byte
    WAIT_S_PARITY,  // Waiting to write (odd) parity bit
    WAIT_S_STOP,  // Waiting to stop and release data pin
    WAIT_S_ACK,  // Waiting for ACK bit, always 0
  };

  State getStateForTesting() const { return state_; }

  uint16_t getClockPulsesForTesting() const { return clock_pulses_; }

 private:
  const static int kBufferArraySize = 17;

  // Called from ISR handler when a bit is received from the PS2 device.
  void isrHandleReceivedBit(int bit);

  // Called from ISR handler when a bit should be sent to the PS2 device.
  void isrHandleSendBit(int bit);

  // Handles an error while reading a bytes from the PS2 device.
  void handleError(const __FlashStringHelper* error);

  // For debugging.  Number of clock pulses since begin().
  volatile uint16_t clock_pulses_;

  // Handlers for this instance of PS2Protocol.
  IsrHandler isr_handler_;
  PS2Debug* volatile debug_;

  // Pins used to communicate with PS2 device.
  uint8_t clock_pin_;
  uint8_t data_pin_;

  // Circular buffer holding bytes received from PS2 device. The ISR handler
  // adds bytes at the head of the buffer, while the read() method removes
  // bytes from the tail.  Note the following conditions:
  //
  //   0 <= head_ < sizeof(buffer_) / sizeof(buffer_[0])
  //   0 <= tail_ < sizeof(buffer_) / sizeof(buffer_[0])
  //   head_ == tail_ : the buffer is empty
  //   head_ + 1 == tail_ : buffer is full
  volatile byte head_;
  volatile byte tail_;
  volatile byte buffer_[kBufferArraySize];

  // The following variables are used from within the ISR.  The |state_| and
  // |current_| can be accessed from loop() when sending a byte to the PS2
  // device.  In this case, the clock pin is held low which essentially disables
  // the ISR, so there should be no race conditions.

  // State of the protocol while comunicating with the PS2 device.  Can be one
  // of the State values.
  volatile State state_;
  volatile byte current_;
  volatile int parity_;
};


// Macros to help declare PS2Protocol variables as either memebers of a class
// of as globals.  See class comment below for how to use them.

#define PS2P_DECLARE(class_name, variable)                             \
    static void PS2P_##variable##_IsrHandler();                        \
    static PS2Protocol* static_PSP2_##variable;                        \
    class PS2P_##variable : public PS2Protocol {                       \
     public:                                                           \
      PS2P_##variable() : PS2Protocol(PS2P_##variable##_IsrHandler) {  \
        static_PSP2_##variable = this;                                 \
      }                                                                \
    } variable;

#define PS2P_IMPLEMENT(class_name, variable)           \
    PS2Protocol*                                       \
        class_name::static_PSP2_##variable = 0;        \
    void class_name::PS2P_##variable##_IsrHandler() {  \
      static_PSP2_##variable->isrHandlerImpl();        \
    }

#define PS2P_GLOBAL(variable)                             \
    void PS2P_##variable##_IsrHandler();                  \
    PS2Protocol variable(PS2P_##variable##_IsrHandler);   \
    void PS2P_##variable##_IsrHandler() {                 \
      variable.isrHandlerImpl();                          \
    }

#endif  // PS2_PROTOCOL_H_
