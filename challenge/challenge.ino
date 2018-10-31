#include <Servo.h>
const int IR_PIN = 5;
const int ECHO_PIN = 9;
const int TRIG_PIN = 10;
const int SERVO_PIN = 13;
const float SOUND_SPEED = 0.034;
const int MIN_ANGLE =0, MAX_ANGLE=180;
Servo myservo;

bool flag, already;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(IR_PIN,INPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(TRIG_PIN,OUTPUT);
  myservo.attach(SERVO_PIN);
}

bool readUltra() {
  digitalWrite (TRIG_PIN, LOW);
  delayMicroseconds (2);
  digitalWrite (TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (TRIG_PIN, LOW);

  long duration = pulseIn (ECHO_PIN, HIGH);
  int distance = (duration*SOUND_SPEED)/2;

  return (distance < 7);
}

void loop() {
  // put your main code here, to run repeatedly:
  int irState = digitalRead(IR_PIN);
  int task;
  int ultraState = !readUltra();

  switch (task) {
    case 0: if(!irState and !task) myservo.write(90), task=1;
    case 1: if(!ultraState and task) myservo.write(0), task=0;
  }
  delay (200);  
//  Serial.println(distance);
}

