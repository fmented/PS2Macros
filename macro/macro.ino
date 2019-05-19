#include "setting.h"

int b1 ,b2;

void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);

init(2,8);
init_2(3,9);

}

void loop() {
  b1 = digitalRead(11);
  b2 = digitalRead(12);
  if (b1 == LOW and b2 == LOW){
    normal_in();
    normal_in_2();
  }
  if (b1 == HIGH and b2 == LOW){
    custom1_in();
    custom1_in_2();
  }
  if (b1 == LOW and b2 == HIGH){
    custom2_in();
    custom2_in_2();
  }
  if (b1 == HIGH and b2 == HIGH){
    custom3_in();
    custom3_in_2();
  }
  
}
