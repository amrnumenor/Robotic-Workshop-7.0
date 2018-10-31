//---------------------BLUETOOTH--------------------//
#include <SoftwareSerial.h>
const int RX_PIN = 10;
const int TX_PIN = 11;

SoftwareSerial btSerial (RX_PIN, TX_PIN);

void setup() {
  Serial.begin (9600);
  btSerial.begin (38400); 
  Serial.println ("Enter AT command: ");
}

void loop() {
  //keep reading from Serial Monitor and send data to HC-05
  if (Serial.available()) btSerial.write (Serial.read());
  //keep reading from HC-05 and send data to Serial Mon.
  if (btSerial.available()) Serial.write (btSerial.read());
}
