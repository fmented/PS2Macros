#ifndef COM_H
#define COM_H
uint8_t usb[8]{};

void sendKey(){
  Serial.write(usb,8);
}

void releaseKey(){
  usb[0]=0;
  usb[2]=0;
  sendKey();
}
void pressKey(){
  sendKey();
  releaseKey();
}

#endif
