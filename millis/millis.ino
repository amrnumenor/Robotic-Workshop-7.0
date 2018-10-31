unsigned long currentMillis;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  //print current time
  Serial.println(currentMillis);
}
