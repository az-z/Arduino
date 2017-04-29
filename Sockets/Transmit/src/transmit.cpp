#include "Outlet.h"
#include <Arduino.h>

#define ledPin 13 // Onboard LED = digital pin 13

const bool ON = true;
const bool OFF = false;

const int8_t DataPin = 4;
// Outlet outlet(DATA_PIN); //  make a new outlet instance with

class Socket_t : public Outlet {
protected:
  int Channel;
  bool State; // current state of the Socket_t
  // long OnTime; // time to turn it on
  // long OffTime; // time to turn it off

  // lets have 12 hour intervals. Converting into milisecs
  unsigned long IntervalMilSecs = 12 * 60 * 60 * 1000;
  // unsigned long const DurationMillSecs = 43200000 ; //12*60*60*1000

  unsigned long PrevMillSecs; // the previous value of the call to mills()
public:
  Socket_t(int ch, bool state, int8_t Hour, int DPin) : Outlet(DPin) {
    Channel = ch;
    State = state;
    toggle(Channel, State);
    // DurationMillSecs = Hour * 60000; // in minutes for testing
    IntervalMilSecs = Hour * 360000; // in milisecs
    PrevMillSecs = 0;
  };
  void SetState(bool St) {
    State = St;
    toggle(Channel, State);
  };
  bool getState() { return State; };
  void Update(unsigned long currMills) {
    if (currMills - PrevMillSecs >= IntervalMilSecs) {
      State = (State == ON)
                  ? OFF
                  : ON; // Switch the State after current time is over Dur
      toggle(Channel, State);
      PrevMillSecs = currMills;
    };
  };
};

Socket_t Lamp(1, ON, 3, DataPin);
Socket_t Vent(2, ON, 1, DataPin);
long timestop;

void setup() {
  pinMode(ledPin, HIGH);
  Serial.begin(9600);
  timestop = 0;
  /*
     Here i'll magically setup the Sockets per channel. For now i pair them
     before runing this program
   */
}

void loop() {
  delay(180000); // 30 minutes delay
  timestop += 180000;
  Serial.print("Waited : ");
  Serial.print(timestop / 60000); // convert to minutes
  Serial.println(" minutes");
  Lamp.Update(millis());
  if (Lamp.getState()) { // turn Vent only if the Lamp is on
    Vent.Update(millis());
  } else
    Vent.SetState(OFF);
}
