#include <Arduino.h>

// #include "aprintf.h"
#include <aprintf.h>

// Push_Led.ino

//
// Turn LED only when the previous state of the  push btn was "ON"
//

int PinLed = 2;
int PinBtn = 10;
int ON = 1;
int OFF = 0;
int state;
char BLAH;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PinLed, OUTPUT);
  pinMode(PinBtn, INPUT_PULLUP);
  state = digitalRead(PinBtn);
}

void TurnLed(int flag) {
  if (flag) {
    digitalWrite(PinLed, HIGH);
  } else {
    digitalWrite(PinLed, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*  Serial.println(digitalRead(PinBtn));
    Serial.println(state,DEC) ;
   */
  // ardprintf("Lets see - %s",BLAH);
  char answer = 'Y';
  state = ardprintf(&answer);
  (state == digitalRead(PinBtn)) ?: state = !digitalRead(PinBtn);
  delay(300);  // wait for a second
}
