#include <Wire.h>

const int MIN_ADR = 0, MAX_ADR = 127;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Scanner\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  int nDevices; //no. of address found

  Serial.println("Scanning...");

  // scan I2C 7 bit addressing devices
  for (int address = MIN_ADR; address < MAX_ADR; address++) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmission to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    int error = Wire.endTransmission();

    if(error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) Serial.print("0");
      Serial.print(address,HEX);
      Serial.println(" !");
      nDevices++; //increment by 1 if address found
    }
    else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) Serial.print("0");
      Serial.println(address,HEX);
    }
  }

  if (nDevices == 0) Serial.println("No I2C devices found\n");
  else Serial.println("done\n");

  delay(3000);
}
