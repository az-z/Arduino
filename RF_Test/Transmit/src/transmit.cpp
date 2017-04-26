#include <Arduino.h>
#include "Outlet.h"

// #define rfReceivePin A0  //RF Receiver pin = Analog pin 0
#define ledPin 13        //Onboard LED = digital pin 13
//
//  unsigned int data = 0;   // variable used to store received data
//  const unsigned int upperThreshold = 70;  //upper threshold value
//  const unsigned int lowerThreshold = 50;  //lower threshold value

 const int DATA_PIN = 4;
 Outlet outlet(DATA_PIN); //  make a new outlet instance with
 const bool ON = true;
 const bool OFF = false;

 void setup(){
   pinMode(ledPin, HIGH);
   Serial.begin(9600);
 }

void loop(){
  pinMode(ledPin, HIGH);

  outlet.toggle(1, ON); //  turn ch1 on
  delay(1500);
  // outlet.toggle(2, ON); //  turn ch2 on
  // delay(1500);
  // outlet.toggle(3, ON); //  turn ch3 on
  // delay(1500);
  // outlet.toggle(4, ON); //  turn ch1 on
  // delay(1500);
  // outlet.toggle(5, ON); //  turn ch2 on
  // delay(1500);
  // outlet.toggle(6, ON); //  turn ch3 on
  // delay(1500);

  pinMode(ledPin, LOW);
  outlet.toggle(1, OFF);
  delay(500);
  // outlet.toggle(2, OFF);
  // delay(1500);
  // outlet.toggle(3, OFF);
  // delay(1500);
  // outlet.toggle(4, OFF); //  turn ch1 on
  // delay(1500);
  // outlet.toggle(5, OFF); //  turn ch2 on
  // delay(1500);
  // outlet.toggle(6, OFF); //  turn ch3 on
  // delay(1500);
}

 // void loop(){
 //   data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
 //
 //    if(data>upperThreshold){
 //     digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
 //     Serial.println(data);
 //   }
 //
 //   if(data<lowerThreshold){
 //     digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
 //     Serial.println(data);
 //   }
 // }
