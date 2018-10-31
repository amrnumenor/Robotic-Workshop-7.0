void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    int inputInt=Serial.parseInt();
    //Serial.println(inputInt);
    if(inputInt >= 1 && inputInt <= 9) Serial.println("Integer has been entered");    
    //else Serial.println("Wrong Integer has been entered");
  }
}
