#include <Arduino.h>
int Pin = 13;

void setup() {
  // put your setup code here, to run once:

  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:

  pinMode(Pin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Pin, HIGH);  // set the LED on
  delay(5000);              // wait for a second
  digitalWrite(Pin, LOW);   // set the LED off
  delay(10000);
  Serial.println("test");
}
