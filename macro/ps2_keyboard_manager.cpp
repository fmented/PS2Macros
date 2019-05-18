
#include "ps2_keyboard_manager.h"

#include "ps2_debug.h"
#include "ps2_protocol.h"

static const PS2Keyboard::KeyCode kLSHFT = PS2Keyboard::KC_LSHFT;
static const PS2Keyboard::KeyCode kLCTRL = PS2Keyboard::KC_LCTRL;
static const PS2Keyboard::KeyCode kLALT = PS2Keyboard::KC_LALT;
static const PS2Keyboard::KeyCode kLGUI = PS2Keyboard::KC_LGUI;
static const PS2Keyboard::KeyCode kRSHFT = PS2Keyboard::KC_RSHFT;
static const PS2Keyboard::KeyCode kRCTRL = PS2Keyboard::KC_RCTRL;
static const PS2Keyboard::KeyCode kRALT = PS2Keyboard::KC_RALT;
static const PS2Keyboard::KeyCode kRGUI = PS2Keyboard::KC_RGUI;

#define numberof(a) (sizeof(a)/sizeof((a)[0]))

PS2KeyboardManager::Report::Report() : modifiers(0) {
  memset(keycodes, 0, sizeof(keycodes));
}

PS2KeyboardManager::Report::Report(const PS2KeyboardManager::Report& other)
    : modifiers(other.modifiers) {
  memcpy(keycodes, other.keycodes, sizeof(keycodes));
}

void PS2KeyboardManager::Report::operator=(
    const PS2KeyboardManager::Report& other) {
  modifiers = other.modifiers;
  memcpy(keycodes, other.keycodes, sizeof(keycodes));
}

bool PS2KeyboardManager::Report::isShiftPressed() {
  return (modifiers & (M_LSHFT | M_RSHFT)) != 0;
}

bool PS2KeyboardManager::Report::isControlPressed() {
  return (modifiers & (M_LCTRL | M_RCTRL)) != 0;
}

bool PS2KeyboardManager::Report::isAltPressed() {
  return (modifiers & (M_LALT | M_RALT)) != 0;
}

bool PS2KeyboardManager::Report::isGuiPressed() {
  return (modifiers & (M_LGUI | M_RGUI)) != 0;
}

bool PS2KeyboardManager::Report::isKeyPressed(PS2Keyboard::KeyCode keycode) {
  for (int i = 0; i < numberof(keycodes); ++i) {
    if (keycode == keycodes[i])
      return true;
  }
  return false;
}

PS2KeyboardManager::PS2KeyboardManager()
    : last_report_(0),
      ps2_keyboard_(0),
      debug_(0),
      interval_(0),
      leds_(0) {
  memset(pressed_, 0, sizeof(pressed_));
}

PS2KeyboardManager::~PS2KeyboardManager() {
  end();
}

bool PS2KeyboardManager::begin(PS2Keyboard* ps2_keyboard,
                               int interval,
                               PS2Debug* debug) {
  if (!ps2_keyboard)
    return false;

  ps2_keyboard_ = ps2_keyboard;
  debug_ = debug;
  interval_ = interval;
  // TODO: send a reset command to keyboard?
  return true;
}

int PS2KeyboardManager::available() {
  int count = ps2_keyboard_->available();
  if (count == 0 && interval_ > 0) {
    if (millis() - last_report_ > interval_)
      count = 1;
  }
  if (debug_)
    debug_->recordManagerAvailable(count);
  return count;
}

PS2KeyboardManager::Report PS2KeyboardManager::read() {
  if (ps2_keyboard_->available() > 0)
    processKey(transformKey(ps2_keyboard_->read()));

  // See page 62-63 in HID11_1.pdf for more details.
  Report report;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_LSHFT) ? M_LSHFT : 0;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_LCTRL) ? M_LCTRL : 0;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_LALT) ? M_LALT : 0;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_LGUI) ? M_LGUI : 0;

  report.modifiers |= isKeyPressed(PS2Keyboard::KC_RSHFT) ? M_RSHFT : 0;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_RCTRL) ? M_RCTRL : 0;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_RALT) ? M_RALT : 0;
  report.modifiers |= isKeyPressed(PS2Keyboard::KC_RGUI) ? M_RGUI : 0;

  collectKeysDown(&report);
  return report;
}

bool PS2KeyboardManager::isShiftPressed() {
  return isKeyPressed(PS2Keyboard::KC_LSHFT) ||
      isKeyPressed(PS2Keyboard::KC_RSHFT);
}

bool PS2KeyboardManager::isControlPressed() {
  return isKeyPressed(PS2Keyboard::KC_LCTRL) ||
      isKeyPressed(PS2Keyboard::KC_RCTRL);
}

bool PS2KeyboardManager::isAltPressed() {
  return isKeyPressed(PS2Keyboard::KC_LALT) ||
      isKeyPressed(PS2Keyboard::KC_RALT);
}

bool PS2KeyboardManager::isGuiPressed() {
  return isKeyPressed(PS2Keyboard::KC_LGUI) ||
      isKeyPressed(PS2Keyboard::KC_RGUI);
}

bool PS2KeyboardManager::isKeyPressed(PS2Keyboard::KeyCode keycode) {
  int index = keycode / 8;
  int bit = keycode % 8;
  return (pressed_[index] & (1 << bit)) != 0;
}

void PS2KeyboardManager::resetKeyboard() {
  ps2_keyboard_->protocol()->writeAndWait(0xFF);  // Responds with ACK (0xFA)
  memset(pressed_, 0, sizeof(pressed_));
  leds_ = 0;
}

void PS2KeyboardManager::setTypematicRateAndDelay(byte arg) {
  ps2_keyboard_->protocol()->writeAndWait(0xF3);  // Responds with ACK (0xFA)
  ps2_keyboard_->protocol()->writeAndWait(arg);  // Responds with ACK (0xFA)
}

void PS2KeyboardManager::setLEDs(byte mask, byte leds) {
  leds_ &= ~mask;
  leds_ |= mask & leds;
  ps2_keyboard_->protocol()->writeAndWait(0xED);  // Responds with ACK (0xFA)
  ps2_keyboard_->protocol()->writeAndWait(leds_);  // Responds with ACK (0xFA)
}

void PS2KeyboardManager::end() {
  last_report_ = 0;
  ps2_keyboard_ = 0;
  memset(pressed_, 0, sizeof(pressed_));
  leds_ = 0;
}

PS2Keyboard::Key PS2KeyboardManager::transformKey(PS2Keyboard::Key key) {
  return key;
}

void PS2KeyboardManager::processKey(PS2Keyboard::Key key) {
  int index = key.code() / 8;
  int bit = key.code() % 8;
  if (key.type() == PS2Keyboard::KEY_PRESSED) {
    pressed_[index] |= 1 << bit;
  } else {
    pressed_[index] &= ~(1 << bit);

    // Handle LEDs.
    byte mask = 0;
    switch (key.code()) {
      case PS2Keyboard::KC_SCROLL_LOCK:
        mask = LED_SCROLL_LOCK;
        break;
      case PS2Keyboard::KC_KP_NUM_LOCK:
        mask = LED_NUM_LOCK;
        break;
      case PS2Keyboard::KC_CAPS_LOCK:
        mask = LED_CAPS_LOCK;
        break;
      default:
        break;
    }
    if (mask != 0)
      setLEDs(mask, ~leds_);
  }
}

void PS2KeyboardManager::collectKeysDown(Report* report) {
  int pos = 0;
  for (PS2Keyboard::KeyCode kc = PS2Keyboard::KC_FIRST_NON_MODIFIER_KEYCODE;
       kc < PS2Keyboard::KC_COUNT_NON_MODIFIER_KEYCODE;
       kc = static_cast<PS2Keyboard::KeyCode>(kc + 1)) {
    if (isKeyPressed(kc)) {
      if  (pos == numberof(report->keycodes))
        break;

      report->keycodes[pos++] = kc;

      // Workaround for missing break code for the Pause key.
      if (kc == PS2Keyboard::KC_PAUSE) {
        int index = kc / 8;
        int bit = kc % 8;
        pressed_[index] &= ~(1 << bit);
      }
    }
  }

  // If more keys are pressed than can fit into the report, return a phantom
  // state by setting all keycoes to ERROR_ROLL_OVER.
  if (pos == numberof(report->keycodes)) {
    memset(report->keycodes, PS2Keyboard::KC_ERROR_ROLL_OVER,
           numberof(report->keycodes));
  }
}
