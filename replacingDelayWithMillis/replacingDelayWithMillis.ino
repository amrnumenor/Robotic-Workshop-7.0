const int LED_PIN = 2;

unsigned long previousMillis;
int ledState;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - previousMillis > 1000) {
    ledState = !ledState;
    digitalWrite (LED_PIN, ledState);
    //store the last time you blink the LED
    previousMillis = millis();
  }
}
