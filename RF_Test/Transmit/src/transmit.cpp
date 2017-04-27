#include "Outlet.h"
#include <Arduino.h>

#define ledPin 13 // Onboard LED = digital pin 13

const bool ON = true;
const bool OFF = false;

// Why i can't move these 2 lines into the class?
// Actually a normal person would inherit this class and add timings as i do
// with Socket_t
const int DATA_PIN = 4;
// Outlet outlet(DATA_PIN); //  make a new outlet instance with

class Socket_t : public Outlet {
protected:
  int Channel;
  bool State; // current state of the Socket_t
  // long OnTime; // time to turn it on
  // long OffTime; // time to turn it off

  unsigned long DurationMillSecs; // = Hour*120000;//lets pass 1 hour and make
                                  // it into 2 minutes
  // unsigned long const DurationMillSecs = 50000;//43200000; //12*60*60*1000
  // duration of the 12 hours
  // on / 12 hours off cycle in milisecs
  unsigned long prevMillSecs; // the previous value of the call to mills()
public:
  Socket_t(int ch, bool state, int8_t Hour, DATA_PIN) {
    Channel = ch;
    State = state;
    Outlet::Outlet(DATA_PIN);
    toggle(Channel, State);
    DurationMillSecs = Hour * 60000; // in minutes for testing
    prevMillSecs = 0;
  };
  void Update(unsigned long currMills) {
    if (currMills - prevMillSecs >= DurationMillSecs) {
      State = (State == ON)
                  ? OFF
                  : ON; // Switch the State after current time is over Dur
      toggle(Channel, State);
      prevMillSecs = currMills;
    };
  };
  bool getState() { return State; };
};

Socket_t Lamp(1, ON, 1);
Socket_t Vent(2, ON, 2);

void setup() {
  pinMode(ledPin, HIGH);
  Serial.begin(9600);
  //  Serial.println("Setup");
  /*
     Here i'll magically setup the Sockets per channel. For now i pair them
     before runing this program
   */
}

void loop() {
  pinMode(ledPin, HIGH);
  Serial.println("Waiting 10 secs");
  delay(10000);
  // Lamp.Update(millis());
  // if (Lamp.getState()) { // turn Vent only if the Lamp is on
  //   Vent.Update(millis());
  // }
}
