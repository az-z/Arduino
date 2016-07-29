#include <Arduino.h>
int switchPin = 2;

void setup() {
  Serial.begin(9600);         //
  pinMode(switchPin, INPUT);  // sets the digital pin as input to read switch
}

int sensorvalue;  // analogRead(switchPin);
float voltage;    //  sensorvalue * 5.0 / 1023.0 ;
void loop() {     // run over and over again {
  Serial.print("Read switch input: ");
  sensorvalue = analogRead(switchPin);
  voltage = sensorvalue * 5.0 / 1023.0;

  Serial.println(voltage);      // Read the pin and display the value
  Serial.println(sensorvalue);  // Read the pin and display the value

  delay(500);
}
