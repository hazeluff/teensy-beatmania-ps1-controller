#include "pins.h"

#define PIN_LED PIN_D6
#define ATTN PIN_B0
#define CLK PIN_B1
#define CMD PIN_B2
#define ACK PIN_B3
#define DATA PIN_B7

int state = 0; 

//0=idle (waiting for CMD 0x01)
//1=return id (waiting for request controller data)
//2=send 0x5A
//3=send {SLCT,_,_,STRT,UP,RIGHT,DOWN,LEFT}
//4=send {L2,R2,L1,R1,/\,O,X,|_|}


void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);

  // Setup Interface Pins
  pinMode(ATTN, INPUT);
  pinMode(CLK, INPUT);
  pinMode(CMDLK, INPUT);
  pinMode(ACK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

//Use CLK down edge to time start of byte send/receive
//ACK low whenever end of each byte (CMD read)
// If 2 or more CLK=HIGH, reset byte
void loop() {
  
}
