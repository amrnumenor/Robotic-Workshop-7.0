//--------------------------LCD I2C-------------------------//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int LCD_ADDRESS = 0x3F;

LiquidCrystal_I2C lcd(LCD_ADDRESS, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
  lcd.print("Saalihaan Say Hi");
  delay(2000);
//  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
//  lcd.print("Roboteam");
//  lcd.setCursor(0,1);
//  lcd.print("Robotic Workshop 7.0");
}
