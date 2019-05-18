
#include "ps2_debug.h"

#include <HardwareSerial.h>

#include "ps2_keyboard.h"
#include "ps2_keyboard_manager.h"
#include "ps2_protocol.h"

#define numberof(a) (sizeof(a)/sizeof((a)[0]))

PS2Debug::PS2Debug()
    : protocol_(0), keyboard_(0), manager_(0), count_(0), last_report_time_(0) {
  memset(error_, 0, sizeof(error_));
  memset(histogram_protocol_, 0, sizeof(histogram_protocol_));
  memset(histogram_keyboard_, 0, sizeof(histogram_keyboard_));
  memset(histogram_manager_, 0, sizeof(histogram_manager_));
}

PS2Debug::~PS2Debug() {
  end();
}

bool PS2Debug::begin(PS2KeyboardManager* manager) {
  return init(manager, manager_->keyboard(), manager->keyboard()->protocol());
}

bool PS2Debug::begin(PS2Keyboard* keyboard) {
  return init(0, keyboard, keyboard->protocol());
}

bool PS2Debug::begin(PS2Protocol* protocol) {
  return init(0, 0, protocol);
}

bool PS2Debug::init(PS2KeyboardManager* manager,
                    PS2Keyboard* keyboard,
                    PS2Protocol* protocol) {
  manager_ = manager;
  keyboard_ = keyboard;
  protocol_ = protocol;

  Serial.begin(9600);
  Serial.println(F("Ready"));
  return true;
}

void PS2Debug::dump() {
  for (int i = 0; i < count_; ++i)
    Serial.println(const_cast<const __FlashStringHelper*>(error_[i]));
  count_ = 0;

  unsigned long now = millis();
  if (now - last_report_time_ < 2000)
    return;

  if (protocol_) {
    Serial.print(F("Protocol: Clocks="));
    Serial.print(protocol_->getClockPulsesForTesting());
    Serial.print(F(" State="));
    Serial.println(protocol_->getStateForTesting());
  }

  if (keyboard_) {
    Serial.print(F("Keyboard: State="));
    Serial.println(keyboard_->getStateForTesting());
  }

  if (manager_) {
    Serial.print(F("Manager: "));
    if (manager_->isShiftPressed())
      Serial.print(F("SHFT "));
    if (manager_->isControlPressed())
      Serial.print(F("CTRL "));
    if (manager_->isAltPressed())
      Serial.print(F("ALT "));
    if (manager_->isGuiPressed())
      Serial.print(F("GUI "));

    for (PS2Keyboard::KeyCode kc = PS2Keyboard::KC_FIRST_NON_MODIFIER_KEYCODE;
         kc < PS2Keyboard::KC_COUNT_NON_MODIFIER_KEYCODE;
         kc = static_cast<PS2Keyboard::KeyCode>(kc + 1)) {
      if (manager_->isKeyPressed(kc)) {
        Serial.print(kc, HEX);
        Serial.print(F(" "));
      }
    }

    byte leds = manager_->getLEDs();
    if (leds & PS2KeyboardManager::LED_SCROLL_LOCK)
      Serial.print(F("SCRL "));
    if (leds & PS2KeyboardManager::LED_NUM_LOCK)
      Serial.print(F("NUML "));
    if (leds & PS2KeyboardManager::LED_CAPS_LOCK)
      Serial.print(F("CAPL "));

    Serial.println();
  }

  dumpHistograms();
  Serial.println();
  Serial.println();
  last_report_time_ = now;
}

void PS2Debug::dumpReport(const PS2KeyboardManager::Report& report) {
  Serial.print(F("Report: m="));
  Serial.print(report.modifiers, HEX);
  Serial.print(F(" "));
  for (int i = 0; i < numberof(report.keycodes); ++i) {
    Serial.print(report.keycodes[i], HEX);
    Serial.print(F(" "));
  }
  Serial.println();
}

void PS2Debug::dumpHistograms() {
  if (protocol_) {
    dumpHistogram(F("Protocol counts:"), histogram_protocol_,
                  numberof(histogram_protocol_));
  }

  if (keyboard_) {
    dumpHistogram(F("Keyboard counts:"), histogram_keyboard_,
                  numberof(histogram_keyboard_));
  }

  if (manager_) {
    dumpHistogram(F("Manager counts:"), histogram_manager_,
                  numberof(histogram_manager_));
  }
}

void PS2Debug::dumpHistogram(const __FlashStringHelper* title,
                             int* histogram,
                             int length) {
  Serial.print(title);
  for (int i = 0; i < length; ++i) {
    Serial.print(F(" "));
    Serial.print(histogram[i]);
  }
  Serial.println();
}

void PS2Debug::end() {
  Serial.println(F("Terminated"));
  manager_ = 0;
  keyboard_ = 0;
  protocol_ = 0;
  count_ = 0;
  last_report_time_ = 0;
  Serial.end();
}

void PS2Debug::recordProtocolAvailable(int count) {
  recordHistogram(histogram_protocol_, count);
}

void PS2Debug::recordKeyboardAvailable(int count) {
  recordHistogram(histogram_keyboard_, count);
}

void PS2Debug::recordManagerAvailable(int count) {
  recordHistogram(histogram_manager_, count);
}

// static
void PS2Debug::recordHistogram(int* array, int count) {
  switch (count) {
    case 0:
      break;
    case 1:
      ++array[0];
      break;
    case 2:
      ++array[1];
      break;
    case 3:
      ++array[2];
      break;
    case 4:
    case 5:
      ++array[3];
      break;
    case 6:
    case 7:
    case 8:
      ++array[4];
      break;
    default:
      ++array[5];
      break;
  }
}

void PS2Debug::ErrorHandler(const __FlashStringHelper* error) volatile {
  if (count_ >= kMaxErrors)
    return;
  error_[count_++] = error;
}
