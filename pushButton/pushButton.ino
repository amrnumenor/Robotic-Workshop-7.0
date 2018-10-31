const int BUTTON_PIN = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //initialize BUTTON_PIN as input
  pinMode (BUTTON_PIN, INPUT);
}

void loop() {
  //read button state either HIGH or LOW (1 or 0)
  int buttonState = digitalRead (BUTTON_PIN);

  //print button state
  Serial.println (buttonState);
}
