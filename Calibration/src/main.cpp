#include <Arduino.h>

int SensorInputPin = A0 ;
int OutLedPin = 9 ;
int MaxRead, MinRead = 0 ;

void setup(/* arguments */) {
  /* code */
  Serial.begin(9600);
  pinMode(13, OUTPUT) ;
  digitalWrite(13, HIGH);
  for (size_t i = 0; i < 15; i++) {
    int SensorValue = analogRead(SensorInputPin);
    if (SensorValue >MaxRead) {
      MaxRead = SensorValue;
    } else if (SensorValue < MinRead) {
      SensorValue = MinRead;
    }
    Serial.print("Sensor Value :");
    Serial.print(SensorValue);
    Serial.print("\t MaxRead :");
    Serial.print(MaxRead);
    Serial.print("\t MinRead :");
    Serial.println(MinRead);
    delay(100);
  }
  digitalWrite(13, LOW);
}


void loop () {
int SensorValue = analogRead(SensorInputPin);
int OutValue =constrain(map(SensorValue, MinRead, MaxRead, 0, 127),0,127);
analogWrite(OutLedPin, OutValue);
Serial.print("\t OutValue :");
Serial.println(OutValue) ;
delay(1000);
}
