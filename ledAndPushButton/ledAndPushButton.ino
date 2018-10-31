//------------------LED & PUSH BUTTON-----------------//
const int LED_PIN = 2;
const int BUTTON_PIN = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (LED_PIN, OUTPUT); //inititalize LED_PIN as output
  pinMode (BUTTON_PIN, INPUT); //initialize BUTTON_PIN as input
}

void loop() {
  // put your main code here, to run repeatedly:
  //read button state either HIGH or LOW (1 or 0)
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);
  digitalWrite(LED_PIN, HIGH);
  /*delay(1000);
  digitalWrite(LED_PIN,LOW);
  delay(1000);*/
  if (!buttonState) digitalWrite (LED_PIN, HIGH);
  else digitalWrite (LED_PIN, LOW);
}
