#include "com.h"
#include "keytab.h"

int hold;


void normal(uint16_t x){
if (!x and hold==1){
  hold=0;
  releaseKey();
}
else{
switch (x){
        case (41):   //esc
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (58):   //f1
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (59):   //f2
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (60):   //f3
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (61):   //f4
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (62):   //f5
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (63):   //f6
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (64):   //f7
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (65):   //f8
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (66):   //f9
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (67):   //f10
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (68):   //f11
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (69):   //f12
              usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (70):   //print scr
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (71):   //scroll lock
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (72):   //pause
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (53):   //`
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (30):   //1
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (31):   //2
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (32):   //3
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (33):   //4
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (34):   //5
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (35):   //6
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (36):   //7
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (37):   //8
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (38):   //9
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (39):   //0
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (45):   //-
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (46):   //=
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (42):   //backspace
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (73):   //insert
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (74):   //home
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (75):   //pageup
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (83):   //num lock
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (84):   //kp/
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (85):   //kp*
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (86):   //kp-
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (43):   //tab
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (20):   //q
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (26):   //w
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (8):   //e
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (21):   //r
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (23):   //t
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (28):   //y
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (24):   //u
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (12):   //i
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (18):   //o
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (19):   //p
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (47):   //[
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (48):   //]
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (49):   //\
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (76):   //del
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (77):   //end
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (78):   //pagedown
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (95):   //kp7
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (96):   //kp8
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (97):   //kp9
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (87):   //kp+
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (57):   //caps lock
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (4):   //a
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (22):   //s
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (7):   //d
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (9):   //f
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (10):   //g
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (11):   //h
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (13):   //j
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (14):   //k
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (15):   //l
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (51):   //;
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (52):   //'
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (40):   //enter
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (92):   //kp4
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (93):   //kp5
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (94):   //kp6
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (225):   //lshift
               hold=1;
               usb[0]=SHIFT; 
               sendKey();                   
        break;
         case (29):   //z
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (27):   //x
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (6):   //c
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (25):   //v
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (5):   //b
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (17):   //n
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (16):   //m
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (54):   //,
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (55):   //.
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (56):   ///
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (229):   //rshift
               hold=1;
               usb[0]=SHIFT; 
               sendKey(); 
        break;
         case (89):   //kp1
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (90):   //kp2
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (91):   //kp3
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (224):   //lctrl
               hold=1;
               usb[0]=CTRL; 
               sendKey();
        break;
         case (227):   //lgui
               hold=1;
               usb[0]=GUI; 
               sendKey();
        break;
         case (226):   //lalt
               hold=1;
               usb[0]=ALT; 
               sendKey(); 
        break;
         case (44):   //space
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (230):   //ralt
               hold=1;
               usb[0]=ALT; 
               sendKey(); 
        break;
         case (231):   //rgui
               hold=1;
               usb[0]=GUI; 
               sendKey(); 
        break;
         case (101):   //menu
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (228):   //rctrl
               hold=1;
               usb[0]=CTRL; 
               sendKey(); 
        break;
        case (80):   //leftarrow
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (82):  //uparrow
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (81):   //downarrow
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (79):   //rightarrow
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (98):   //kp0
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case (99):   //kp.
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case (88):   //kpenter
               usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;  



//second keyboard
         case(1041):   //esc
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1058):   //f1
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1059):   //f2
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1060):   //f3
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1061):   //f4
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1062):   //f5
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1063):   //f6
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1064):   //f7
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1065):   //f8
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1066):   //f9
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1067):   //f10
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1068):   //f11
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1069):   //f12
        x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1070):   //print scr
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1071):   //scroll lock
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1072):   //pause
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1053):   //`
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1030):   //1
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1031):   //2
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1032):   //3
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1033):   //4
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1034):   //5
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1035):   //6
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1036):   //7
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1037):   //8
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1038):   //9
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1039):   //0
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1045):   //-
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1046):   //=
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1042):   //backspace
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1073):   //insert
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1074):   //home
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1075):   //pageup
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1083):   //num lock
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1084):   //kp/
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1085):   //kp*
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1086):   //kp-
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1043):   //tab
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1020):   //q
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1026):   //w
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1008):   //e
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1021):   //r
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1023):   //t
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1028):   //y
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1024):   //u
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1012):   //i
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1018):   //o
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1019):   //p
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1047):   //[
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1048):   //]
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1049):   //\
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1076):   //del
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1077):   //end
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1078):   //pagedown
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1095):   //kp7
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1096):   //kp8
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1097):   //kp9
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1087):   //kp+
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1057):   //caps lock
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1004):   //a
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1022):   //s
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1007):   //d
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1009):   //f
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1010):   //g
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1011):   //h
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1013):   //j
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1014):   //k
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1015):   //l
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1051):   //;
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1052):   //'
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1040):   //enter
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1092):   //kp4
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1093):   //kp5
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1094):   //kp6
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1225):   //lshift
               hold=1;
               usb[0]=SHIFT; 
               sendKey(); 
        break;
         case(1029):   //z
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1027):   //x
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1006):   //c
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1025):   //v
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(105):   //b
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1017):   //n
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1016):   //m
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1054):   //,
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1055):   //.
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1056):   ///
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1229):   //rshift
               hold=1;
               usb[0]=SHIFT; 
               sendKey(); 
        break;
         case(1089):   //kp1
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1090):   //kp2
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1091):   //kp3
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1224):   //lctrl
               hold=1;
               usb[0]=CTRL; 
               sendKey(); 
        break;
         case(1227):   //lgui
               hold=1;
               usb[0]=GUI; 
               sendKey(); 
        break;
         case(1226):   //lalt
               hold=1;
               usb[0]=ALT; 
               sendKey(); 
        break;
         case(1044):   //space
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1230):   //ralt
               hold=1;
               usb[0]=ALT; 
               sendKey(); 
        break;
         case(1231):   //rgui
               hold=1;
               usb[0]=GUI; 
               sendKey(); 
        break;
         case(1101):   //menu
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1228):   //rctrl
               hold=1;
               usb[0]=CTRL; 
               sendKey(); 
        break;
        case(1080):   //leftarrow
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1082):  //uparrow
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1081):   //downarrow
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1079):   //rightarrow
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1098):   //kp0
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
        case(1099):   //kp.
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;
         case(1088):   //kpenter
         x=x-1000;      usb[2]=x;    sendKey();    usb[2]=0;    sendKey();
        break;       
      } 
  }
}
