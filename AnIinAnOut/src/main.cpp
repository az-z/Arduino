#include <Arduino.h>

const int InPin = A2;
const int OutPin = A5;
int SensorValue = 0;
int OutValue = 0;


void setup() { Serial.begin(9600); }

void loop(/* arguments */) {
  SensorValue = analogRead(InPin);
  OutValue = map(SensorValue, 0, 1023, 0, 255);
  analogWrite(OutPin, OutValue);
  Serial.print("Sensor = ");
  Serial.print(SensorValue);
  Serial.print("\t output = ");
  Serial.println(OutValue);

  // delayMicroseconds(3000000);
  delay(1000);
}
