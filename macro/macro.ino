
#include "setting.h"


void setup() {
  Serial.begin(9600);

init(2,4); // means first keyboard clock connected to pin 2 and keyboard data to pin 4
init_2(3,5); // means second keyboard clock connected to pin 3 and keyboard data to pin 5

}

void loop() {
  check_in(); //you can edit this function in setting.h
  check_in_2(); //you can edit this function in setting.h
}
