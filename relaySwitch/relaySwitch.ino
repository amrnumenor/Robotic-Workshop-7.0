//-------------------RELAY---------------------//
// relay connected to digital pin 7
const int RELAY_PIN = 7;

void setup() {
  // initialize RELAY_PIN as output
  pinMode (RELAY_PIN, OUTPUT);
}

void loop() {
  // toggle the pin state each 2s
  digitalWrite (RELAY_PIN, LOW);
  delay(2000);
  digitalWrite (RELAY_PIN, HIGH);
  delay(2000);
}
