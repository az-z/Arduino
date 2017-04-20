#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

// To get this thing to work - either use this init with the setBacklightPin
// or combine init with setBacklightPin as:
//LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3,POSITIVE);

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7);


// #define BACKLIGHT_PIN     13

void setup()
{
  lcd.setBacklightPin(3,POSITIVE);
  // lcd.setBacklight(HIGH); // NOTE: You can turn the backlight off by setting it to LOW instead of HIGH
// lcd.backlight();
  lcd.begin(16, 2);
  lcd.clear();


}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("http://mklec.com");
  lcd.setCursor(0,1);
  lcd.print("I2C BLAHH Demo");
  delay(1000);
  lcd.autoscroll();
}
