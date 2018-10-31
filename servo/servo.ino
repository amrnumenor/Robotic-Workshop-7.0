//---------------------- SERVO ------------------------//
#include <Servo.h>

const int SERVO_PIN = 9;
Servo myservo; //create servo object to control a servo

const int MIN_ANGLE = 0, MAX_ANGLE = 180;

void setup() {
  myservo.attach(SERVO_PIN); //attaches the servo pin  
}

void loop() {
  static int pos;

  for (pos = MIN_ANGLE; pos <= MAX_ANGLE; pos++) {
    //tell servo to go to position in variable 'pos'
    myservo.write(pos);
    //waits 15ms for the servo to reach the position
    delay(15);
  }

  for (pos = MAX_ANGLE; pos >= MIN_ANGLE; pos--) {
    myservo.write(pos);
    delay(15);
  }
}
