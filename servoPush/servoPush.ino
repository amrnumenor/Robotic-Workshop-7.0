#include <Servo.h>
const int SERVO_PIN=9;
const int BUTTON_PIN=3;
Servo myservo;
int pos;
bool flag;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode (BUTTON_PIN, INPUT);
  myservo.attach (SERVO_PIN);
}

void loop() {
  if (!digitalRead(BUTTON_PIN)){
    if (pos == 0)
      flag = 0;
    else if (pos == 180)
      flag = 1;

   !flag ? pos++ : pos--;

    myservo.write (pos);
  }
  delay  (15);
}
