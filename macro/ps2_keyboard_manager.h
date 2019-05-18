#ifndef PS2_KEYBOARD_MANAGER_H_
#define PS2_KEYBOARD_MANAGER_H_

#include "ps2_keyboard.h"

class PS2Debug;

/**
 * This class manages a PS2 keyboard.  It tracks the state of all keys,
 * remembers which modifiers are pressed, and turns keyboard LEDs on and off.
 * The keyboard manager can also produce USB HID keyboard reports to ease
 * the implementation of a USB keyboard using an arduino.
 */
class PS2KeyboardManager {
 public:
  enum Modifier {
    M_LCTRL = 1 << 0,
    M_LSHFT = 1 << 1,
    M_LALT = 1 << 2,
    M_LGUI = 1 << 3,
    M_RCTRL = 1 << 4,
    M_RSHFT = 1 << 5,
    M_RALT = 1 << 6,
    M_RGUI = 1 << 7
  };

  // Bits used with setLEDs() method.  These values may be ORed together.
  enum LED {
    LED_SCROLL_LOCK = 1 << 0,
    LED_NUM_LOCK = 1 << 1,
    LED_CAPS_LOCK = 1 << 2
  };

  // Information required for a USB HID keyboard report.
  struct Report {
    Report();
    Report(const Report& other);
    void operator=(const Report& other);

    bool isShiftPressed();
    bool isControlPressed();
    bool isAltPressed();
    bool isGuiPressed();
    bool isKeyPressed(PS2Keyboard::KeyCode keycode);

    byte modifiers;
    byte keycodes[6];
  };

  PS2KeyboardManager();
  virtual ~PS2KeyboardManager();

  // Initialize the PS2KeyboardManager object.  This is normally called once
  // from the setup() function.
  //
  // |ps2_keyboard| will be used to receive key codes from the PS2 keyboard.
  // It is assumed |ps2_keyboard| has already been initialized (i.e. its
  // begin() method has already been called).
  //
  // |interval| is the maximum amount of time in milliseconds that should
  // elapse before before new USB report becomes available when the state of
  // keys has not changed.  That is, if the user has not pressed or released
  // any keys on the keyboard, then after the internal has elapsed, available()
  // will return 1 and a new report with the current state will be available
  // by calling read().  Note that when a key is pressed or released
  // available() returns >1 immediately.
  //
  // Use an interval of zero to disable periodic reports.  In this case,
  // available() will return >0 only when a key is actually pressed or
  // released.
  //
  // Returns true if the object is initialized correctly, and false otherwise.
  bool begin(PS2Keyboard* ps2_keyboard, int interval, PS2Debug* debug=0);

  // Returns the number of reports available for reading.  The new report is
  // available either because the user has pressed or released a key, or
  // because the time since the last report has exceeded the interval given
  // in begin().
  int available();

  // Get the inforation required for building a USB HID report.
  Report read();

  // Determines whether the corresponding modifier key is currently held down
  // or not.
  bool isShiftPressed();
  bool isControlPressed();
  bool isAltPressed();
  bool isGuiPressed();

  // Determines whether the corresponding key is currently held down or not.
  bool isKeyPressed(PS2Keyboard::KeyCode keycode);

  // Does a power-on reset of keyboard.
  void resetKeyboard();

  // Loads default typematic rate/delay.  For acceptable values of |args| see
  // http://www.computer-engineering.org/ps2keyboard/
  void setTypematicRateAndDelay(byte arg);

  // Turns on or off the LEDs on the keyboard.  Both |mask| and |leds| should
  // be the bitwise OR of one or LED_xxx values.  |mask| specifies which LEDs
  // to change, and |leds| specifies their new values.
  void setLEDs(byte mask, byte leds);
  byte getLEDs() { return leds_; }

  // Shuts down this PS2ToUSBKeyboard.  The PS2Keyboard given to begin() can
  // now be used for other purposes.
  void end();

  // Get the PS2 protocol object associated with this keyboard.
  PS2Keyboard* keyboard() { return ps2_keyboard_; }

 private:
  // Derived classes can override this method to remap keys.  By default no
  // transformation is performed.
  virtual PS2Keyboard::Key transformKey(PS2Keyboard::Key key);

  void processKey(PS2Keyboard::Key key);
  void collectKeysDown(Report* report);

  // Time that available() last returned true.
  unsigned long last_report_;

  PS2Keyboard* ps2_keyboard_;
  PS2Debug* debug_;

  // Interval specified in begin()call.
  int interval_;

  // This mask represents whether a key is pressed or not.  Each bit corresponds
  // to one key.  There are a most 256 key codes, and there are 8 bits per byte,
  // we need 256/8=32 bytes to store the entire mask.
  static const int kMaskSize = 256 / 8;
  byte pressed_[kMaskSize];

  // State of the keyboard LEDs.
  byte leds_;
};

#endif  // PS2_KEYBOARD_MANAGER_H_
