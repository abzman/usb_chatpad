#include <Chatpad.h>
#include "Keyboard.h"

//shift key = 129
//green key = 130
//orange key = 132
//enter = 99
//left arrow = 85
//right arrow = 81
//backspace = 113
//messenger key = 131

Chatpad pad;

uint8_t mode = 0;
uint8_t caps = 0;
uint8_t mode1Pin = 2;
uint8_t mode2Pin = 3;
uint8_t capsPin = 4;

//char mode0A[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132};
  char mode0A[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'7','6','5','4','3','2','1',-1,-1,-1,-1,-1,-1,-1,-1,-1,'u','y','t','r','e','w','q',-1,-1,-1,-1,-1,-1,-1,-1,-1,'j','h','g','f','d','s','a',-1,-1,-1,-1,-1,-1,-1,-1,-1,'n','b','v','c','x','z',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'m','.',' ',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,',',-1,'p','0','9','8',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'l',-1,-1,'o','i','k',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  char mode1A[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'7','6','5','4','3','2','1',-1,-1,-1,-1,-1,-1,-1,-1,-1,'&','^','%','#',-1,'@','!',-1,-1,-1,-1,-1,-1,-1,-1,-1,'\'','/',':','}','{',-1,'~',-1,-1,-1,-1,-1,-1,-1,-1,-1,'<','|','-','>','<','`',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'>','?',' ',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,':',-1,')','0','9','8',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,']',-1,-1,'(','*','[',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  char mode2A[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'7','6','5','4','3','2','1',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'$',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'"','\\',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'+','_',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'¿',' ',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,',',-1,'=','0','9','8',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'l',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
   char capsA[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'7','6','5','4','3','2','1',-1,-1,-1,-1,-1,-1,-1,-1,-1,'U','Y','T','R','E','W','Q',-1,-1,-1,-1,-1,-1,-1,-1,-1,'J','H','G','F','D','S','A',-1,-1,-1,-1,-1,-1,-1,-1,-1,'N','B','V','C','X','Z',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'M','.',' ',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,',',-1,'P','0','9','8',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,'l',-1,-1,'O','I','K',-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void print_keys(Chatpad &pad, Chatpad::keycode_t code,
                Chatpad::eventtype_t type) {
  if (type == Chatpad::Down) {
    char a = -1;
    if(mode == 0 && caps == 0) a = mode0A[code];
    else if(mode == 0 && caps == 1) a = capsA[code];
    else if(mode == 1) a = mode1A[code];
    else if(mode == 2) a = mode2A[code];
    if(a != -1) Keyboard.print(a);
    //Serial.print(a);
    //Serial.print(code);
    //Serial.println(" down");
    if (code == 132 && mode == 2) mode = 0;
    else if (code == 132) mode = 2;
    if (code == 130 && mode == 1) mode = 0;
    else if (code == 130) mode = 1;
    if (code == 85) Keyboard.press(0xD8); //left
    if (code == 81) Keyboard.press(0xD7); //right
    if (code == 113) Keyboard.press(0xB2); //backspace
    if (code == 131) Keyboard.press(0x80); //leftcontrol
    if (code == 99) Keyboard.press(0xB0); //enter
    if (code == 38 && mode ==2) Keyboard.press(0xDA); //up
    if (code == 54 && mode ==2) Keyboard.press(0xD9); //down
    if (code == 55 && mode ==2) Keyboard.press(0xD8); //left
    if (code == 53 && mode ==2) Keyboard.press(0xD7); //right
    
    if(code == 129 && caps == 1) caps = 0;
    else if(code == 129) caps = 1;

  }
  if (type == Chatpad::Up) {
    char a = pad.toAscii(code);
    
    if (code == 129 && mode != 2) caps = 0;
    if (code == 85) Keyboard.release(0xD8); //left
    if (code == 81) Keyboard.release(0xD7); //right
    if (code == 113) Keyboard.release(0xB2); //backspace
    if (code == 131) Keyboard.release(0x80); //leftcontrol
    if (code == 99) Keyboard.release(0xB0); //enter
    if (code == 38 && mode ==2) Keyboard.release(0xDA); //up
    if (code == 54 && mode ==2) Keyboard.release(0xD9); //down
    if (code == 55 && mode ==2) Keyboard.release(0xD8); //left
    if (code == 53 && mode ==2) Keyboard.release(0xD7); //right
    
     // Serial.print(a); 
     // Serial.print(code); 
     // Serial.println(" up");
  }
}

void setup() {
  //Serial.begin(57600);
  pad.init(Serial1, print_keys);
  // initialize control over the keyboard:
  Keyboard.begin();
  pinMode(capsPin,OUTPUT);
  pinMode(mode1Pin,OUTPUT);
  pinMode(mode2Pin,OUTPUT);
}

void loop() {
  pad.poll();
  if(caps ==1)
  {
    digitalWrite(capsPin, 1);
  }
  else
  {
    digitalWrite(capsPin, 0);
  }
  if(mode == 0)
  {
    digitalWrite(mode1Pin, 0);
    digitalWrite(mode2Pin, 0);
  }
  if(mode == 1)
  {
    digitalWrite(mode1Pin, 1);
    digitalWrite(mode2Pin, 0);
  }
  if(mode == 2)
  {
    digitalWrite(mode1Pin, 0);
    digitalWrite(mode2Pin, 1);
  }
}
