#include <Arduino.h>

char PORT_D = 0;
void setup() {
  Serial.begin(9600);
  DDRB = B00111111 ;
  PORTB = B00111111; // enable builtin pull up resistors;
  DDRB = (0<<PB0); // dig pin 9
}
void loop(/* arguments */) {

  PORT_D = PINB ;

 Serial.print(PORT_D,BIN);
 // delayMicroseconds(100000);
 delay(1000);
 Serial.println('-');
};
