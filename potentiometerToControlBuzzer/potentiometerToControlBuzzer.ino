//------------USING POTENTIOMETER TO CONTROL BUZZER-----------//
//buzzer connected to digital pwm pin 9
//const int BUZZER_PIN = 9;
//potentiometer connected to analog pin A0
const int POT_PIN = A0;
const int LED_PIN = 3;

void setup() {
  // initialize BUZZER_PIN as output
  Serial.begin(9600);
  //pinMode (BUZZER_PIN, OUTPUT);
  //initialize POT_PIN as input
  pinMode (POT_PIN, INPUT);
  pinMode (LED_PIN, OUTPUT);
}

void loop() {
  //read potentiometer analog value
  int potVal = analogRead(POT_PIN);
  //int buzVal = analogRead(BUZZER_PIN);
  //scale it to use with buzzer
  potVal = map(potVal, 0, 1023, 0, 255);
  analogWrite(LED_PIN,potVal);
  //write value from potentiometer to buzzer
  //analogWrite (BUZZER_PIN, potVal);
  Serial.println(potVal);
  //Serial.println(buzVal);
}
