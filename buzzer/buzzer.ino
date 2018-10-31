//---------------BUZZER---------------//
//buzzer connected to digital pwm pin 9
const int BUZZER_PIN = 9;
//maximum pwm value
const int MAX_PWM = 255;
//to hold the value of pwm. By default, initialize to 0
int pwmVal;

void setup() {
  // put your setup code here, to run once:
  //initialize BUZZER_PIN as output
  pinMode (BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // write analog value to buzzer (0-255)
  analogWrite (BUZZER_PIN, pwmVal);
  //Serial.println(pwmVal);
  pwmVal++;

  if (pwmVal > MAX_PWM) pwmVal = 0; //pwmVal initialize back to 0 if its value is greater than 255
  delay (50);
}
