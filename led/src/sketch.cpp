#include <Arduino.h>

/*
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
*/
int Pin = 13;
void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:

  pinMode(Pin, OUTPUT);
}

void loop() {
  digitalWrite(Pin, HIGH);  // set the LED on
  delay(250);              // wait for a second
  digitalWrite(Pin, LOW);   // set the LED off
  delay(1000);              // wait for a second
}
