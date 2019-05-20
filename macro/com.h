#ifndef COM_H
#define COM_H


uint8_t usb[8]{0}; //Keyboard report. learn more here : https://wiki.osdev.org/USB_Human_Interface_Devices



void sendKey(){
  Serial.write(usb,8);

}

void releaseKey(){
  usb[0]=0;
  usb[2]=0;
  sendKey();
}



void pressKey(uint8_t modifier, uint8_t key1,uint8_t key2=0,uint8_t key3=0,uint8_t key4=0,uint8_t key5=0,uint8_t key6=0 ){

  usb[0]=modifier;
  usb[2]=key1;
  usb[3]=key2;
  usb[4]=key3;
  usb[5]=key4;
  usb[6]=key5;
  usb[7]=key6;
  sendKey();
  releaseKey();
  }
  


#endif
