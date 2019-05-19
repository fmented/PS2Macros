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



void pressKey(uint8_t modifier, uint8_t keypress){

  usb[0]=modifier;
  usb[2]=keypress;
  sendKey();
  releaseKey();
  }
  
void wordKey(String w){
  int n = w.length()+1;
  char words[n];
  w.toCharArray(words,n);
  for (int i=0; i < n; i++){
    
      pressKey(0,words[i]);
  }
}

#endif
