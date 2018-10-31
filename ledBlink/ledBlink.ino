//----------------- LED BLINK -------------------//
// LED connected to digital pin 2
const int LED_PIN = 13;

//the setup  function
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (LED_PIN, HIGH);
  delay(5000);
  digitalWrite (LED_PIN, LOW);
  delay(5000);
}
