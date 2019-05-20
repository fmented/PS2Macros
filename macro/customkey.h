#include "keytab.h"
#include "com.h"
#include "event_to_hid.h"


void custom1(uint16_t x){
switch (x){
        case (41):   //esc
        //do something
Serial.println("key1");
        break;
        case (58):   //f1
        //do something
        break;
         case (59):   //f2
        //do something
        break;
         case (60):   //f3
        //do something
        break;
         case (61):   //f4
        //do something
        break;
         case (62):   //f5
        //do something
        break;
         case (63):   //f6
        //do something
        break;
         case (64):   //f7
        //do something
        break;
         case (65):   //f8
        //do something
        break;
         case (66):   //f9
        //do something
        break;
         case (67):   //f10
        //do something
        break;
         case (68):   //f11
        //do something
        break;
         case (69):   //f12
        //do something
        break;
         case (70):   //print scr
         //do something
        break;
        case (71):   //scroll lock
         //do something
        break;
        case (72):   //pause
         //do something
        break;
        case (53):   //`
         //do something
        break;
        case (30):   //1
         //do something
        break;
        case (31):   //2
         //do something
        break;
        case (32):   //3
         //do something
        break;
        case (33):   //4
         //do something
        break;
        case (34):   //5
         //do something
        break;
        case (35):   //6
         //do something
        break;
         case (36):   //7
         //do something
        break;
         case (37):   //8
         //do something
        break;
         case (38):   //9
         //do something
        break;
         case (39):   //0
         //do something
        break;
         case (45):   //-
         //do something
        break;
         case (46):   //=
         //do something
        break;
         case (42):   //backspace
         //do something
        break;
         case (73):   //insert
         //do something
        break;
         case (74):   //home
         //do something
        break;
         case (75):   //pageup
         //do something
        break;
         case (83):   //num lock
         //do something
        break;
         case (84):   //kp/
         //do something
        break;
         case (85):   //kp*
         //do something
        break;
         case (86):   //kp-
         //do something
        break;
         case (43):   //tab
         //do something
        break;
         case (20):   //q
         //do something
        break;
         case (26):   //w
         //do something
        break;
         case (8):   //e
         //do something
        break;
         case (21):   //r
         //do something
        break;
         case (23):   //t
         //do something
        break;
         case (28):   //y
         //do something
        break;
         case (24):   //u
         //do something
        break;
         case (12):   //i
         //do something
        break;
         case (18):   //o
         //do something
        break;
         case (19):   //p
         //do something
        break;
         case (47):   //[
         //do something
        break;
         case (48):   //]
         //do something
        break;
         case (49):   //\
         //do something
        break;
         case (76):   //del
         //do something
        break;
         case (77):   //end
         //do something
        break;
         case (78):   //pagedown
         //do something
        break;
         case (95):   //kp7
         //do something
        break;
         case (96):   //kp8
         //do something
        break;
         case (97):   //kp9
         //do something
        break;
         case (87):   //kp+
         //do something
        break;
         case (57):   //caps lock
         //do something
        break;
         case (4):   //a
         //do something
        break;
         case (22):   //s
         //do something
        break;
         case (7):   //d
         //do something
        break;
         case (9):   //f
         //do something
        break;
         case (10):   //g
         //do something
        break;
         case (11):   //h
         //do something
        break;
         case (13):   //j
         //do something
        break;
         case (14):   //k
         //do something
        break;
         case (15):   //l
         //do something
        break;
         case (51):   //;
         //do something
        break;
         case (52):   //'
         //do something
        break;
         case (40):   //enter
         //do something
        break;
         case (92):   //kp4
         //do something
        break;
         case (93):   //kp5
         //do something
        break;
         case (94):   //kp6
         //do something
        break;
         case (225):   //lshift
         //do something
        break;
         case (29):   //z
         //do something
        break;
         case (27):   //x
         //do something
        break;
         case (6):   //c
         //do something
        break;
         case (25):   //v
         //do something
        break;
         case (5):   //b
         //do something
        break;
         case (17):   //n
         //do something
        break;
         case (16):   //m
         //do something
        break;
         case (54):   //,
         //do something
        break;
         case (55):   //.
         //do something
        break;
         case (56):   ///
         //do something
        break;
         case (229):   //rshift
         //do something
        break;
         case (89):   //kp1
         //do something
        break;
         case (90):   //kp2
         //do something
        break;
         case (91):   //kp3
         //do something
        break;
         case (224):   //lctrl
         //do something
        break;
         case (227):   //lgui
         //do something
        break;
         case (226):   //lalt
         //do something
        break;
         case (44):   //space
         //do something
        break;
        case (230):   //ralt
         //do something
        break;
         case (231):   //rgui
         //do something
        break;
         case (101):   //menu
         //do something
        break;
         case (228):   //rctrl
         //do something
        break;
        case (80):   //leftarrow
         //do something
        break;
         case (82):  //uparrow
         //do something
        break;
         case (81):   //downarrow
         //do something
        break;
         case (79):   //rightarrow
         //do something
        break;
         case (98):   //kp0
         //do something
        break;
        case (99):   //kp.
         //do something
        break;
         case (88):   //kpenter
         //do something
        break;  




//second keyboard
         case(1041):   //esc
        //do something
Serial.println("key2");
        break;
        case(1058):   //f1
        //do something
        break;
         case(1059):   //f2
        //do something
        break;
         case(1060):   //f3
        //do something
        break;
         case(1061):   //f4
        //do something
        break;
         case(1062):   //f5
        //do something
        break;
         case(1063):   //f6
        //do something
        break;
         case(1064):   //f7
        //do something
        break;
         case(1065):   //f8
        //do something
        break;
         case(1066):   //f9
        //do something
        break;
         case(1067):   //f10
        //do something
        break;
         case(1068):   //f11
        //do something
        break;
         case(1069):   //f12
        //do something
        break;
         case(1070):   //print scr
         //do something
        break;
        case(1071):   //scroll lock
         //do something
        break;
        case(1072):   //pause
         //do something
        break;
        case(1053):   //`
         //do something
        break;
        case(1030):   //1
         //do something
        break;
        case(1031):   //2
         //do something
        break;
        case(1032):   //3
         //do something
        break;
        case(1033):   //4
         //do something
        break;
        case(1034):   //5
         //do something
        break;
        case(1035):   //6
         //do something
        break;
         case(1036):   //7
         //do something
        break;
         case(1037):   //8
         //do something
        break;
         case(1038):   //9
         //do something
        break;
         case(1039):   //0
         //do something
        break;
         case(1045):   //-
         //do something
        break;
         case(1046):   //=
         //do something
        break;
         case(1042):   //backspace
         //do something
        break;
         case(1073):   //insert
         //do something
        break;
         case(1074):   //home
         //do something
        break;
         case(1075):   //pageup
         //do something
        break;
         case(1083):   //num lock
         //do something
        break;
         case(1084):   //kp/
         //do something
        break;
         case(1085):   //kp*
         //do something
        break;
         case(1086):   //kp-
         //do something
        break;
         case(1043):   //tab
         //do something
        break;
         case(1020):   //q
         //do something
        break;
         case(1026):   //w
         //do something
        break;
         case(1008):   //e
         //do something
        break;
         case(1021):   //r
         //do something
        break;
         case(1023):   //t
         //do something
        break;
         case(1028):   //y
         //do something
        break;
         case(1024):   //u
         //do something
        break;
         case(1012):   //i
         //do something
        break;
         case(1018):   //o
         //do something
        break;
         case(1019):   //p
         //do something
        break;
         case(1047):   //[
         //do something
        break;
         case(1048):   //]
         //do something
        break;
         case(1049):   //\
         //do something
        break;
         case(1076):   //del
         //do something
        break;
         case(1077):   //end
         //do something
        break;
         case(1078):   //pagedown
         //do something
        break;
         case(1095):   //kp7
         //do something
        break;
         case(1096):   //kp8
         //do something
        break;
         case(1097):   //kp9
         //do something
        break;
         case(1087):   //kp+
         //do something
        break;
         case(1057):   //caps lock
         //do something
        break;
         case(1004):   //a
         //do something
        break;
         case(1022):   //s
         //do something
        break;
         case(1007):   //d
         //do something
        break;
         case(1009):   //f
         //do something
        break;
         case(1010):   //g
         //do something
        break;
         case(1011):   //h
         //do something
        break;
         case(1013):   //j
         //do something
        break;
         case(1014):   //k
         //do something
        break;
         case(1015):   //l
         //do something
        break;
         case(1051):   //;
         //do something
        break;
         case(1052):   //'
         //do something
        break;
         case(1040):   //enter
         //do something
        break;
         case(1092):   //kp4
         //do something
        break;
         case(1093):   //kp5
         //do something
        break;
         case(1094):   //kp6
         //do something
        break;
         case(1225):   //lshift
         //do something
        break;
         case(1029):   //z
         //do something
        break;
         case(1027):   //x
         //do something
        break;
         case(1006):   //c
         //do something
        break;
         case(1025):   //v
         //do something
        break;
         case(105):   //b
         //do something
        break;
         case(1017):   //n
         //do something
        break;
         case(1016):   //m
         //do something
        break;
         case(1054):   //,
         //do something
        break;
         case(1055):   //.
         //do something
        break;
         case(1056):   ///
         //do something
        break;
         case(1229):   //rshift
         //do something
        break;
         case(1089):   //kp1
         //do something
        break;
         case(1090):   //kp2
         //do something
        break;
         case(1091):   //kp3
         //do something
        break;
         case(1224):   //lctrl
         //do something
        break;
         case(1227):   //lgui
         //do something
        break;
         case(1226):   //lalt
         //do something
        break;
         case(1044):   //space
         //do something
        break;
        case(1230):   //ralt
         //do something
        break;
         case(1231):   //rgui
         //do something
        break;
         case(1101):   //menu
         //do something
        break;
         case(1228):   //rctrl
         //do something
        break;
        case(1080):   //leftarrow
         //do something
        break;
         case(1082):  //uparrow
         //do something
        break;
         case(1081):   //downarrow
         //do something
        break;
         case(1079):   //rightarrow
         //do something
        break;
         case(1098):   //kp0
         //do something
        break;
        case(1099):   //kp.
         //do something
        break;
         case(1088):   //kpenter
         //do something
        break;       
      } 
}
