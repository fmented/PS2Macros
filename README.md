# PS2KeyboardMacro
turn a ps2 keyboard into a macro keyboard using Arduino Uno

Requirements:
    PS2KeyAdvanced Library,
    Flip (for Windows),
    Keyboard firmware,

connect keyboard clock to pin 2 or 3
connect keyboard data to pin 1 (usually it can be any digital pin but it seems didn't work at least in my case)

you need to modify ksend function
change usb[2] value to any key you want to send
see Keytab.h
if you need a modifier key use:
usb[0]=CTRL; or usb[0]=ALT;
if you need more than one modifier, use:
usb[0]=CTRL+SHIFT;
to send a keystroke use:
sendKey();
make sure to use releaseKey(); everytime you send a keystroke.

note: keyboard LED indicators wouldn't work if keyboard data connected to pin 1.
      done your code before you flash your arduino

      
   

