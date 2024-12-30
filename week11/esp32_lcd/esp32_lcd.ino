#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(39, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();

  lcd.backlight();
  lcd.print("Hello, Kim!");
}

void loop() {
  // Do nothing

}
