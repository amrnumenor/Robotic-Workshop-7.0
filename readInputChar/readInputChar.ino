void setup() {
  Serial.begin(9600); //open serial port to send data
}

void loop() {
  if(Serial.available()) {
    char inputChar=Serial.read();
    Serial.println(inputChar);
    if(inputChar == '1' || inputChar == '9') Serial.println ("Character 1 has been entered");
    else Serial.println("Wrong character entered");
  }  
}
