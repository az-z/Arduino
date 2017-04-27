#include <Arduino.h>
#include "Outlet.h"

#define ledPin 13        //Onboard LED = digital pin 13

const bool ON = true;
const bool OFF = false;

// Why i can't move these 2 lines into the class?
const int DATA_PIN = 4;
Outlet outlet(DATA_PIN); //  make a new outlet instance with


class Socket_t {
private:
  int  Channel;
  bool State; // current state of the Socket_t
  // long OnTime; // time to turn it on
  // long OffTime; // time to turn it off

  unsigned long DurationMillSecs; // = Hour*120000;//lets pass 1 hour and make it into 2 minutes
  // unsigned long const DurationMillSecs = 50000;//43200000; //12*60*60*1000 duration of the 12 hours
                                      // on / 12 hours off cycle in milisecs
  unsigned long prevMillSecs ; // the previous value of the call to mills()
public:
  Socket_t (int ch , bool state, int8_t Hour){
    Channel = ch;
    State = state;
    outlet.toggle(Channel, State);
    DurationMillSecs = Hour*60000; //in minutes for testing
    prevMillSecs = 0;
  };
void Update(unsigned long currMills) {
  if (currMills - prevMillSecs >= DurationMillSecs) {
    State = (State == ON)? OFF:ON; // Switch the State after current time is over Dur
    outlet.toggle(Channel, State);
    prevMillSecs=currMills;
  };
};
};

Socket_t Lamp(1,ON,1);
Socket_t Vent(2,ON,2);

void setup(){
   pinMode(ledPin, HIGH);
   Serial.begin(9600);
  //  Serial.println("Setup");
   /*
   Here i'll magically setup the Sockets per channel. For now i pair them
   before runing this program
   */

}

void loop(){
  pinMode(ledPin, HIGH);
  Serial.println("Waiting 10 secs");
  delay(10000);
  // unsigned long mils = millis();
  Lamp.Update(millis());
  Vent.Update(millis());

  // outlet.toggle(1, ON); //  turn ch1 on
  // delay(1500);
  //
  // pinMode(ledPin, LOW);
  // outlet.toggle(1, OFF);
  // delay(500);
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
