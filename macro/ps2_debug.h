#ifndef DEBUG_H_
#define DEBUG_H_

#include <Arduino.h>

#include "ps2_keyboard_manager.h"

class PS2Keyboard;
class PS2Protocol;

// Class to help debug sketches that use the PS2Utils classes.  Dumps error
// strings from the PS2 utility classes to the console using |Serial|.  This
// class ois optional and not required for proper functioning of the PS2Utils.
//
// Only one instance of this class can be created.
class PS2Debug {
 public:
  PS2Debug();
  ~PS2Debug();

  // Call one of the begin() methods in the sketch's setup() function.
  // This method calls Serial.begin(9600). Subsequent calls to begin() have
  // no effect.
  bool begin(PS2KeyboardManager* manager);
  bool begin(PS2Keyboard* manager);
  bool begin(PS2Protocol* protocol);

  // Dumps the internal state of the PS2 objects to the console.  Regarless of
  // of how often this method is called, it will only dump at most once every
  // to seconds.  Therefore, it may be called  from the loop() function without
  // causing too much debug information to be dumped.
  void dump();

  // Dumps the UDB report to the console.  This funtion is not rate limited.
  void dumpReport(const PS2KeyboardManager::Report& report);

  // Called to terminate the debug helper.  This also calls Serial.end().
  // begin() may be called again to restart debugging.
  void end();

  // The following methods are meant to be called onlt from PS2xxx classes.
  void recordProtocolAvailable(int count);
  void recordKeyboardAvailable(int count);
  void recordManagerAvailable(int count);
  void ErrorHandler(const __FlashStringHelper* error) volatile;

 private:
  static const int kMaxErrors = 32;

  bool init(PS2KeyboardManager* manager,
            PS2Keyboard* keyboard,
            PS2Protocol* protocol);

  static void recordHistogram(int* array, int count);
  void dumpHistograms();
  void dumpHistogram(const __FlashStringHelper* title,
                     int* histogram,
                     int length);

  PS2Protocol* protocol_;
  PS2Keyboard* keyboard_;
  PS2KeyboardManager* manager_;
  volatile const __FlashStringHelper* error_[kMaxErrors];
  volatile int count_;
  unsigned long last_report_time_;

  // Count histograms.  Counts how often each of the functions returned
  // a given count from the available() method.
  int histogram_protocol_[6];
  int histogram_keyboard_[6];
  int histogram_manager_[6];
};

#endif  // DEBUG_H_
