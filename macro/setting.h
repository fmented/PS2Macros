#include "ps2_debug.h"
#include "ps2_keyboard.h"
#include "ps2_protocol.h"
#include "customkey.h"
#include "normalkey.h"

static PS2P_GLOBAL(protocol);
static PS2Keyboard keyboard;
static PS2Debug debug;
static PS2P_GLOBAL(protocol2);
static PS2Keyboard keyboard2;
static PS2Debug debug2;

int y;
int z;
int button;


void init(int clk, int data){
  
    protocol.begin(clk, data, &debug);
    keyboard.begin(&protocol, &debug);
    
}

 void init_2(int clk, int data){
  
     protocol2.begin(clk, data, &debug2);
     keyboard2.begin(&protocol2, &debug2);
     
 }

void check_in(){
  
    int count = keyboard.available();
  if (count > 0) {
    PS2Keyboard::Key k1 = keyboard.read();
    
    y = k1.code();
    custom(y);
    
  }


}

void check_in_2(){
  int count = keyboard2.available();
   if (count > 0) {
     PS2Keyboard::Key k2 = keyboard2.read();
     int z = 1000+k2.code();
     custom(z);
   }
 }
