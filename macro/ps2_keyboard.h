#ifndef PS2_KEYBOARD_H_
#define PS2_KEYBOARD_H_

#include <Arduino.h>

class PS2Debug;
class PS2Protocol;

/**
 * Class to decode PS2 make and break codes (collectively known as scan codes)
 * into key codes.  For maximum compatibility with most PS2 keyboards, set 2
 * scan codes are handled.
 *
 * This class must be connected to a PS2Protocol object which handles all the
 * low level communication with the actual keyboard.  Bytes are read from the
 * PS2Protocol object, interpreted as scan codes, and transformed into
 * key codes.
 */
class PS2Keyboard {
 public:
  // Key code values as returned by the read() method.
  //
  // Each key on a PS2 keyboard has a unique KC_xxx key code value.  For
  // example, the "A" key corresponds to KC_A, the "Tab" key corresponds to
  // KC_TAB, and so on.
  //
  // To ease the implementation of a USB keyboard with PS2Keyboard, the values
  // of this enum match USB usage codes.  That is, the values here can be placed
  // directly in the array of USB HID keyboard reports.  See
  // http://www.freebsddiary.org/APC/usb_hid_usages.php, "section 7: Keyboard"
  // for more details.
  enum KeyCode {
    KC_FIRST_NON_MODIFIER_KEYCODE,

    // 0x
    KC_NO_EVENT = KC_FIRST_NON_MODIFIER_KEYCODE,
    KC_ERROR_ROLL_OVER,
    KC_POST_FAIL,
    KC_ERROR_UNDEFINED,
    KC_A,
    KC_B,
    KC_C,
    KC_D,

    KC_E,
    KC_F,
    KC_G,
    KC_H,
    KC_I,
    KC_J,
    KC_K,
    KC_L,

    // 1x
    KC_M,
    KC_N,
    KC_O,
    KC_P,
    KC_Q,
    KC_R,
    KC_S,
    KC_T,

    KC_U,
    KC_V,
    KC_W,
    KC_X,
    KC_Y,
    KC_Z,
    KC_1,
    KC_2,

    // 2x
    KC_3,
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
    KC_0,

    KC_ENTER,
    KC_ESC,
    KC_BACKSPACE,
    KC_TAB,
    KC_SPACE,
    KC_MINUS,
    KC_EQUAL,
    KC_OPEN_BRACKET,

    // 3x
    KC_CLOSE_BRACKET,
    KC_BACKSLASH,
    KC_HASH,
    KC_SEMI_COLON,
    KC_QUOTE,
    KC_BACK_QUOTE,
    KC_COMMA,
    KC_PERIOD,

    KC_SLASH,
    KC_CAPS_LOCK,
    KC_F1,
    KC_F2,
    KC_F3,
    KC_F4,
    KC_F5,
    KC_F6,

    // 4x
    KC_F7,
    KC_F8,
    KC_F9,
    KC_F10,
    KC_F11,
    KC_F12,
    KC_PRINT_SCREEN,
    KC_SCROLL_LOCK,

    KC_PAUSE,
    KC_INSERT,
    KC_HOME,
    KC_PGUP,
    KC_DELETE,
    KC_END,
    KC_PGDN,
    KC_RIGHT,

    // 5x
    KC_LEFT,
    KC_DOWN,
    KC_UP,
    KC_KP_NUM_LOCK,
    KC_KP_DIV,
    KC_KP_MULT,
    KC_KP_SUB,
    KC_KP_ADD,

    KC_KP_ENTER,
    KC_KP_1,
    KC_KP_2,
    KC_KP_3,
    KC_KP_4,
    KC_KP_5,
    KC_KP_6,
    KC_KP_7,

    // 6x
    KC_KP_8,
    KC_KP_9,
    KC_KP_0,
    KC_KP_DOT,
    KC_NON_US_BACKSLASH,
    KC_APPS,
    KC_POWER,
    KC_KP_EQUAL,

    KC_F13,
    KC_F14,
    KC_F15,
    KC_F16,
    KC_F17,
    KC_F18,
    KC_F19,
    KC_F20,

    // 7x
    KC_F21,
    KC_F22,
    KC_F23,
    KC_F24,
    KC_EXECUTE,
    KC_HELP,
    KC_MENU,
    KC_SELECT,

    KC_STOP,
    KC_AGAIN,
    KC_UNDO,
    KC_CUT,
    KC_COPY,
    KC_PASTE,
    KC_FIND,
    KC_MUTE,

    // 8x
    KC_VOLUME_UP,
    KC_VOLUME_DOWN,
    KC_LOCKING_CAPS_LOCK,
    KC_LOCKING_NUM_LOCK,
    KC_LOCKING_SCROLL_LOCK,
    KC_KP_COMMA,
    KC_KP_EQUAL_SIGN,  // ?
    KC_I18N_1,

    KC_I18N_2,
    KC_I18N_3,
    KC_I18N_4,
    KC_I18N_5,
    KC_I18N_6,
    KC_I18N_7,
    KC_I18N_8,
    KC_I18N_9,

    // 9x
    KC_LANG_1,
    KC_LANG_2,
    KC_LANG_3,
    KC_LANG_4,
    KC_LANG_5,
    KC_LANG_6,
    KC_LANG_7,
    KC_LANG_8,

    KC_LANG_9,
    KC_ALT_ERASE,
    KC_SYS_REQ,
    KC_CANCEL,
    KC_CLEAR,
    KC_PRIOR,
    KC_RETURN,
    KC_SEPARATOR,

    // Ax
    KC_OUT,
    KC_OPER,
    KC_CLEAR_AGAIN,
    KC_CRSEL,
    KC_EXSEL,

    KC_COUNT_NON_MODIFIER_KEYCODE,

    // Modifier keys are not sequential with the rest.
    KC_FIRST_MODIFIER_KEYCODE = 0xE0,
    KC_LCTRL = KC_FIRST_MODIFIER_KEYCODE,
    KC_LSHFT,
    KC_LALT,
    KC_LGUI,
    KC_RCTRL,
    KC_RSHFT,
    KC_RALT,
    KC_RGUI,

    // Add new keycodes above this comment.
    KC_INVALID,
    KC_LAST_KEYCODE = KC_INVALID
  };

  // Value returned by the read() method to indicate whether the key was pressed
  // or released.
  enum EventType {
    KEY_PRESSED,
    KEY_RELEASED
  };

  // Return value of read() method.  Indicates the code of the key and whether
  // it was pressed or released.  Internally, the code and event type are
  // stored as bytes to reduce the amount of memory used.  Unit tests make sure
  // that these values fit into a byte value.
  class Key {
   public:
    Key() : code_(KC_INVALID), type_(KEY_PRESSED) {}
    Key(KeyCode code, EventType type)
        : code_((KeyCode)code),
          type_((EventType)type) {}

    KeyCode code() const { return (KeyCode) code_; }
    EventType type() const { return (EventType) type_; }

    bool isPressed() const { return type_ == KEY_PRESSED; }
    // bool isReleased() const { return type_ == KEY_RELEASED; }

    void set(KeyCode code, EventType type) {
      code_ = code;
      type_ = type;
    }

   private:
    byte code_;
    byte type_;
  };

  // Number of decoded key codes that can be buffered by PS2Keyboard.  If the
  // buffer overflows, newer codes will be dropped with errors reported to
  // the error handler.
  const static int kBufferSize;

  PS2Keyboard();
  ~PS2Keyboard();

  // Initialize the PS2 keyboard object.  This is normally called once from the
  // setup() function.  |ps2_protocol| will be used to read the bytes to
  // be decoded.  It is assumed |ps2_protocol| has already been initialized
  // (i.e. its begin() method has already been called).
  //
  // Returns true if the PS2 keyboard object is initialized correctly, and
  // false otherwise.
  bool begin(PS2Protocol* ps2_protocol, PS2Debug* debug=0);

  // Returns the number of key codes available for reading.
  int available();

  // Reads the next available key code.  Should only be called if available()
  // returns greated than zero.  The return value indicates both the key code
  // and wither the key was pressed or released.
  Key read();

  // Disable the PS2 keyboard object.  The PS2Protocol given to begin() can
  // now be used for other purposes.
  void end();

  // Get the PS2 protocol object associated with this keyboard.
  PS2Protocol* protocol() { return ps2_protocol_; }

  // This is used for testing the PS2Keyboard class.  Does not need to be
  // called in regular programs.
  void processByteForTesting(byte b);

  // States while decoding bytes.
  enum State {
    // Waiting for first byte of scan code.
    WAIT_START,
    // Waiting for first byte of scan code of an extended key code.
    WAIT_EXTENDED,
    // Waiting for break code of a non-extended key code.
    WAIT_BREAK,
    // Waiting for break code of an extended key code.
    WAIT_EXTENDED_BREAK,

    // The following states are for handling the very special Pause/Break key.
    WAIT_FIRST_77,
    WAIT_SECOND_77
  };

  State getStateForTesting() const { return state_; }

 private:
  const static int kBufferArraySize = 17;

  // Reads as many bytes as possible from the PS2 protocol object, filling the
  // buffer with key codes.
  void processBytes();
  void processByte(byte b);

  // Handles an error while deooding bytes from the keyboard.
  void handleError(const __FlashStringHelper* error);

  PS2Protocol* ps2_protocol_;
  PS2Debug* debug_;

  // Circular buffer holding key codes decoded from PS2 keyboard.  Note the
  // following conditions:
  //
  //   0 <= head_ < sizeof(buffer_) / sizeof(byte)
  //   0 <= tail_ < sizeof(buffer_) / sizeof(byte)
  //   head_ == tail_ : the buffer is empty
  //   head_ + 1 == tail_ : buffer is full
  byte head_;
  byte tail_;
  Key buffer_[kBufferArraySize];

  // State of the protocol while reading a byte.  Can be one of the ReadState
  // values.  This variable is only accessed from the ISR handler.
  State state_;
};

#endif  // PS2_KEYBOARD_H_
