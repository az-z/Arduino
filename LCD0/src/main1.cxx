// #include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
// My LCD start address is 0x3F

// initialize the library with the numbers of the interface pins
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// LiquidCrystal_SI2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd(0x3F);


void setup() {
  // set up the LCD's number of columns and rows:
  delay(1000);
   Serial.begin(9600);
  Serial.print("In setup");
  lcd.begin(16, 2);

for(int i = 0; i< 3; i++) {
  lcd.backlight();
  delay(750);
  lcd.noBacklight();
  delay(750); }
  lcd.backlight(); // finish with backlight on

 lcd.setCursor(0,0); //Start at character 4 on line 0
  // Print a message to the LCD.
  lcd.print("hello, world!");
delay(2000);
  Serial.print("Setup - printed message");
}

void loop() {
  // Turn off the blinking cursor:
  lcd.noBlink();
  delay(1000);
  // Turn on the blinking cursor:
  lcd.blink();
  delay(1000);
};
