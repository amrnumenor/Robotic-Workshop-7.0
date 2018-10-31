#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

const int LED = 3;
const int RX = 10;
const int TX = 11;

SoftwareSerial btSerial (RX, TX);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(LED, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  static int brightness, changed;
  if(btSerial.available()){
    char data = btSerial.read();
    if (data=='A') brightness++, changed=true;
    else if (data=='B') brightness--, changed=true;

    brightness = constrain (brightness,0,255);
  }

  if (changed) {
    lcd.clear();
    analogWrite(LED, brightness);
    lcd.print("brightness : ");
    lcd.print(brightness);
    changed = false;
  }
}
