#include "ps2_debug.h"
#include "ps2_keyboard.h"
#include "ps2_protocol.h"
#include "customkey.h"
#include "customkey2.h"
#include "customkey3.h"
#include "normalkey.h"

static PS2P_GLOBAL(protocol);
static PS2Keyboard keyboard;
static PS2Debug debug;
static PS2P_GLOBAL(protocol2);
static PS2Keyboard keyboard2;
static PS2Debug debug2;

int y;
int z;



void init(int clk, int data){
  
    protocol.begin(clk, data, &debug);
    keyboard.begin(&protocol, &debug);
    
}

 void init_2(int clk, int data){
  
     protocol2.begin(clk, data, &debug2);
     keyboard2.begin(&protocol2, &debug2);
     
 }

void custom1_in(){
  
    int count = keyboard.available();
  if (count > 0) {
    PS2Keyboard::Key k1 = keyboard.read();
    
    y = k1.code();
    custom1(y);
    
  }
}

  void custom1_in_2(){
  int count = keyboard2.available();
   if (count > 0) {
     PS2Keyboard::Key k2 = keyboard2.read();
     int z = 1000+k2.code();
     custom1(z);
   }
 }

void custom2_in(){
  
    int count = keyboard.available();
  if (count > 0) {
    PS2Keyboard::Key k1 = keyboard.read();
    
    y = k1.code();
    custom2(y);
    
  }
}

  void custom2_in_2(){
  int count = keyboard2.available();
   if (count > 0) {
     PS2Keyboard::Key k2 = keyboard2.read();
     int z = 1000+k2.code();
     custom2(z);
   }
 }

 void custom3_in(){
  
    int count = keyboard.available();
  if (count > 0) {
    PS2Keyboard::Key k1 = keyboard.read();
    
    y = k1.code();
    custom3(y);
    
  }
}



  void custom3_in_2(){
  int count = keyboard2.available();
   if (count > 0) {
     PS2Keyboard::Key k2 = keyboard2.read();
     int z = 1000+k2.code();
     custom3(z);
   }
 }



 
  void normal_in(){
  
    int count = keyboard.available();
  if (count > 0) {
    PS2Keyboard::Key k1 = keyboard.read();
    
    y = k1.code();
    normal(y);
    
  }
}



 void normal_in_2(){
  int count = keyboard2.available();
   if (count > 0) {
     PS2Keyboard::Key k2 = keyboard2.read();
     int z = 1000+k2.code();
     normal(z);
   }
 }
