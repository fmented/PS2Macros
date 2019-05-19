
#define __PROG_TYPES_COMPAT__ 1
#include "ps2_keyboard.h"

#include <Arduino.h>
#include "ps2_debug.h"
#include "ps2_protocol.h"

// Maps PS2 keyboard make codes to their coresponding KC_xxx values.
// See http://www.computer-engineering.org/ps2keyboard/scancodes2.html for
// details.
//
// Some keys generate one-byte make codes, and others generate two-byte make
// codes.  There is one exception: the PAUSE key generate a multi-byte make
// code.
//
// The first array maps one-byte make codes to KC_xxx values.  The upper part
// of the array is mostly unused.  While we could save memory by reducing the
// sizeof the array, this would require extra checks in the code to prevent
// array out of bounds errors if the keyboard sent incorrect codes.  Since
// progmem is cheap and plentiful, a full array is used here to simplify the
// code.
//
// The second array maps two-byte make codes to KC_xxx values.  The first byte
// of the make codes is always 0xE0, so only the second byte is needed to map
// to a KC_xxx value.  The upper part of this array is also unused, but is
// included here for the same reason as the first array.

#define KC(x) PS2Keyboard::KC_##x
#define KCI KC(INVALID)

PROGMEM static const prog_uchar scanCodeToKeyCode[256] = {
  // 0x
  KCI,  KC(F9),    KCI, KC(F5), KC(F3),   KC(F1),          KC(F2), KC(F12),
  KCI, KC(F10), KC(F8), KC(F6), KC(F4),  KC(TAB),  KC(BACK_QUOTE), KCI,

  // 1x
  KCI, KC(LALT), KC(LSHFT),   KCI, KC(LCTRL), KC(Q), KC(1), KCI,
  KCI,      KCI,     KC(Z), KC(S),     KC(A), KC(W), KC(2), KCI,

  // 2x
  KCI,     KC(C), KC(X), KC(D), KC(E), KC(4), KC(3), KCI,
  KCI, KC(SPACE), KC(V), KC(F), KC(T), KC(R), KC(5), KCI,

  // 3x
  KCI, KC(N), KC(B), KC(H), KC(G), KC(Y), KC(6), KCI,
  KCI,   KCI, KC(M), KC(J), KC(U), KC(7), KC(8), KCI,

  // 4x
  KCI,  KC(COMMA),     KC(K), KC(I),          KC(O), KC(0),      KC(9), KCI,
  KCI, KC(PERIOD), KC(SLASH), KC(L), KC(SEMI_COLON), KC(P),  KC(MINUS), KCI,

  // 5x
               KCI,           KCI, KC(QUOTE),               KCI,
  KC(OPEN_BRACKET),     KC(EQUAL),       KCI,               KCI,
     KC(CAPS_LOCK),     KC(RSHFT), KC(ENTER), KC(CLOSE_BRACKET),
               KCI, KC(BACKSLASH),       KCI,               KCI,

  // 6x
  KCI,      KCI, KCI,      KCI,      KCI, KCI, KC(BACKSPACE), KCI,
  KCI, KC(KP_1), KCI, KC(KP_4), KC(KP_7), KCI,           KCI, KCI,

  // 7x
     KC(KP_0), KC(KP_DOT),        KC(KP_2),        KC(KP_5),
     KC(KP_6),   KC(KP_8),         KC(ESC), KC(KP_NUM_LOCK),
      KC(F11), KC(KP_ADD),        KC(KP_3),      KC(KP_SUB),
  KC(KP_MULT),   KC(KP_9), KC(SCROLL_LOCK),             KCI,

  // 8x
  KCI, KCI, KCI, KC(F7), KCI, KCI, KCI, KCI,
  KCI, KCI, KCI,    KCI, KCI, KCI, KCI, KCI,

  // 9x
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Ax
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Bx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Cx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Dx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Ex
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Fx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
};

// NOTE: print screen generate E0 12 E0 7C.  In this table,
// I ignor the E0 12 part.  There is no key that generates
// only E0 12 and no key that generate E0 7C alone.  Similarly,
// I only handle E0 F0 7C for a release of the print screen.
//
// The reason for this is that my test keyboard would generate
// the following byte stream when holding LSHFT and then pressing
// up:
//
//    12 12 12 ... 12 E0 F0 12 E0 75 ...
//
// The E0 F0 12 sequence does not make sense, it seems like a
// keyboard bug.  I'll see when I use it with a real model M.

PROGMEM static const prog_uchar extScanCodeToKeyCode[256] = {
  // 0x
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // 1x
  KCI, KC(RALT), KCI, KCI, KC(RCTRL), KCI, KCI,      KCI,
  KCI,      KCI, KCI, KCI,       KCI, KCI, KCI, KC(LGUI),

  // 2x
  KCI,   KCI,   KCI,   KCI,   KCI,   KCI,   KCI, KC(RGUI),
  KCI,   KCI,   KCI,   KCI,   KCI,   KCI,   KCI, KC(APPS),

  // 3x
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KC(POWER),
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // 4x
  KCI, KCI,        KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KC(KP_DIV), KCI, KCI, KCI, KCI, KCI,

  // 5x
  KCI, KCI, KCI,          KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KC(KP_ENTER), KCI, KCI, KCI, KCI, KCI,

  // 6x
  KCI,     KCI, KCI,      KCI,      KCI, KCI, KCI, KCI,
  KCI, KC(END), KCI, KC(LEFT), KC(HOME), KCI, KCI, KCI,

  // 7x
  KC(INSERT), KC(DELETE), KC(DOWN), KCI,         KC(RIGHT),   KC(UP), KCI, KCI,
         KCI,        KCI, KC(PGDN), KCI,  KC(PRINT_SCREEN), KC(PGUP), KCI, KCI,

  // 8x
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // 9x
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Ax
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Bx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Cx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Dx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Ex
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,

  // Fx
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
  KCI, KCI, KCI, KCI, KCI, KCI, KCI, KCI,
};

const int PS2Keyboard::kBufferSize = PS2Keyboard::kBufferArraySize - 1;

PS2Keyboard::PS2Keyboard()
    : ps2_protocol_(0),
      debug_(0),
      head_(0),
      tail_(0),
      state_(WAIT_START) {
}

PS2Keyboard::~PS2Keyboard() {
  end();
}

bool PS2Keyboard::begin(PS2Protocol* ps2_protocol, PS2Debug* debug) {
  if (!ps2_protocol)
    return false;

  ps2_protocol_ = ps2_protocol;
  debug_ = debug;
  return true;
}

int PS2Keyboard::available() {
  processBytes();
  int count = (head_ - tail_ + kBufferArraySize) % kBufferArraySize;
  if (debug_)
    debug_->recordKeyboardAvailable(count);
  return count;
}

PS2Keyboard::Key PS2Keyboard::read() {
  // Extract the key code at |tail_| before incrementing it to prevent races.
  Key key = buffer_[tail_];
  tail_  = (tail_ + 1) % kBufferArraySize;
  return key;

  
}

void PS2Keyboard::end() {
  ps2_protocol_ = 0;
  debug_ = 0;
  head_ = 0;
  tail_ = 0;
  state_ = WAIT_START;
}

void PS2Keyboard::handleError(const __FlashStringHelper* error) {
  if (error && debug_)
    debug_->ErrorHandler(error);
  state_ = WAIT_START;
  // TODO: force |ps2_protocol_| to "re-send" byte?
}

void PS2Keyboard::processByteForTesting(byte b) {
  processByte(b);
}

void PS2Keyboard::processBytes() {
  if (!ps2_protocol_)
    return;

  int count = ps2_protocol_->available();
  while (count > 0) {
    byte b = ps2_protocol_->read();
    processByte(b);
    --count;
  }
}

void PS2Keyboard::processByte(byte b) {
  bool is_break = b == 0xF0;
  bool is_extended = b == 0xE0;
  byte kc = KC_INVALID;
  EventType type;

  switch (state_) {
    case WAIT_START:
      if (is_break) {
        state_ = WAIT_BREAK;
      } else if (is_extended) {
        state_ = WAIT_EXTENDED;
      } else if (b == 0xE1) {
        // The user pressed Pause/Break.  The full sequence for this key is:
        //
        //    E1 14 77 E1 F0 14 FO 77
        //
        // The state machine will now look for the second 77 to know when
        // the make code terminates.  Only the specified values above are
        // allowed before the second 77, otherwise an error is reported.
        // The Pause key has no break code.
        state_ = WAIT_FIRST_77;
      } else {
        kc = pgm_read_byte_near(scanCodeToKeyCode + b);
        type = KEY_PRESSED;
      }
      break;
    case WAIT_EXTENDED:
      if (is_extended) {
        handleError(F("EXT while in EXT"));
      } else if (is_break) {
        state_ = WAIT_EXTENDED_BREAK;
      } else {
        kc = pgm_read_byte_near(extScanCodeToKeyCode + b);
        type = KEY_PRESSED;
        state_ = WAIT_START;
      }
      break;
    case WAIT_BREAK:
      if (is_break || is_extended) {
        handleError(F("BRK/EXT while in BRK"));
      } else {
        kc = 0;//pgm_read_byte_near(extScanCodeToKeyCode + b)
        type = KEY_RELEASED;
        state_ = WAIT_START;
      }
      break;
    case WAIT_EXTENDED_BREAK:
      if (is_break || is_extended) {
        handleError(F("BRK/EXT while in EXT_BRK"));
      } else {
        kc = 0;//pgm_read_byte_near(extScanCodeToKeyCode + b)
        type = KEY_RELEASED;
        state_ = WAIT_START;
      }
      break;
    case WAIT_FIRST_77:
    case WAIT_SECOND_77:
      switch(b) {
        case 0x77:
          if (state_ == WAIT_FIRST_77) {
            state_ = WAIT_SECOND_77;
          } else {
            kc = KC_PAUSE;
            type = KEY_PRESSED;
            state_ = WAIT_START;
          }
          break;
        case 0x14:
        case 0xE1:
        case 0xF0:
          break;
        default:
          handleError(F("Invalid code in Pause"));
          break;
      }
      break;
  }

  if (kc != KC_INVALID) {
    byte new_head = (head_ + 1) % kBufferArraySize;
    if (new_head != tail_) {
      buffer_[head_].set((KeyCode)kc, type);
      head_  = (head_ + 1) % kBufferArraySize;
    } else {
      handleError(F("Keyboard buffer overflow"));
    }
  }
}
