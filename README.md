# PS2Macro
turn ps2 keyboards into macro keyboards using Arduino Uno

Requirements:


    PS2Utils library,
   https://github.com/rogerta/PS2Utils
    
    Flip (for Windows),
   https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/FLIP
    
    Keyboard firmware,
   http://www.tinkernut.com/demos/arduino_hid/arduino_hid.zip
   
   
   

connect keyboard's clock to pin 2 or 3 (external interrupt)
and connect keyboard's data to any digital pin




    to remap your keyboard, go to customkey.h
   https://github.com/fmented/PS2Macros/blob/master/macro/customkey.h
    
and

    change usb[2] value to any key you want to send
    see keytab.h
   https://github.com/fmented/PS2Macros/blob/master/macro/keytab.h
    
    
    

you can also add some stuff in setting.h
https://github.com/fmented/PS2Macros/blob/master/macro/setting.h




    if you need a modifier key use:
    usb[0]=CTRL; or usb[0]=ALT;
   
or   

    if you need more than one modifier, use:
    usb[0]=CTRL+SHIFT;



to send a keystroke use:
sendKey();
if you use sendKey(); make sure to use releaseKey(); everytime you send a keystroke, 
otherwise it can causes an error to your computer.
or you can simply use pressKey(); so you don't need to worry if you forgot to releaseKey(); 



    note: Please done your code before you flash your arduino.




Here’s a link to the keycap images:
https://www.dropbox.com/s/ei97zf83ivaa9i4/taran%20keys%205.png?dl=0
thanks to Taran from LTT

      
   

