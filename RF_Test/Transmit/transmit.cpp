#include <Arduino.h>

#define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
#define ledPin 13        //Onboard LED = digital pin 13

 void setup(){
   pinMode(rfTransmitPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
 }

 void loop(){
   for(int i=4000; i>5; i=i-(i/3)){
     digitalWrite(rfTransmitPin, HIGH);     //Transmit a HIGH signal
     digitalWrite(ledPin, HIGH);            //Turn the LED on
     delay(6000);                           //Wait for 1 second 3

     digitalWrite(rfTransmitPin,LOW);      //Transmit a LOW signal
     digitalWrite(ledPin, LOW);            //Turn the LED off
     delay(i);                            //Variable delay
   }
 }
