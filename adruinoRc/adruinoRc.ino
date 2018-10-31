//---------------------ADRUINO RC--------------------//
#include <SoftwareSerial.h>
#include <Servo.h>
const int IR = 12;
const int LDR1 = A0;
const int LDR2 = A1;
const int LDR3 = A2;
const int RX_PIN = 10;
const int TX_PIN = 11;
const int EN_A_LEFT = 6;
const int IN_1_LEFT = 8;
const int IN_2_LEFT = 7;
const int EN_B_RIGHT = 5;
const int IN_3_RIGHT = 4;
const int IN_4_RIGHT = 2;
const int SERVO = 9;
unsigned long startTime = millis();
Servo myServo;
int teta=180;
int sensor[3] = {A0, A1, A2};
int maxVal [3] = {0,0,0};
int minVal [3] = {1023, 1023, 1023};
int threshold [3];
bool lineFollowTrue;
SoftwareSerial btSerial (RX_PIN, TX_PIN);

void linesensor() {
   bool ldrVal1 = analogRead(LDR1)>threshold[0];
   bool ldrVal2 = analogRead(LDR2)>threshold[1];
   bool ldrVal3 = analogRead(LDR3)>threshold[2];

   static bool turnLeft, turnRight;
   static int lastError;

  if (!ldrVal1 and !ldrVal2 and !ldrVal3)
    {
      if (lastError == 1)
        turnLeft = true;
      else if (lastError == 2)
        turnRight = true;
    }
  else if(ldrVal1) {
    turnLeft = true, lastError = 1;
  }

  else if(ldrVal3) {
    turnRight = true, lastError = 2; 
  }

  else if(ldrVal2) {
    turnLeft = false, turnRight = false;
  }
  if (turnLeft){
    digitalWrite (IN_1_LEFT, LOW);
    digitalWrite (IN_2_LEFT, HIGH);
    analogWrite (EN_A_LEFT, 0);
    digitalWrite (IN_3_RIGHT, HIGH);
    digitalWrite (IN_4_RIGHT, LOW);
    analogWrite (EN_B_RIGHT, 100);
  }
  else if(turnRight) {
    digitalWrite (IN_1_LEFT, HIGH);
    digitalWrite (IN_2_LEFT, LOW);
    analogWrite (EN_A_LEFT, 120);
    digitalWrite (IN_3_RIGHT, LOW);
    digitalWrite (IN_4_RIGHT, HIGH);
    analogWrite (EN_B_RIGHT, 0);
  }
  else {
    digitalWrite (IN_1_LEFT, HIGH);
    digitalWrite (IN_2_LEFT, LOW);
    analogWrite (EN_A_LEFT, 115);
    digitalWrite (IN_3_RIGHT, HIGH);
    digitalWrite (IN_4_RIGHT, LOW);
    analogWrite (EN_B_RIGHT, 115 );
  }
}

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600); //AT+UART baud rate
  pinMode (EN_A_LEFT, OUTPUT);
  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  pinMode (EN_B_RIGHT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
  pinMode (IR, INPUT);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  myServo.attach(SERVO);
  myServo.write(teta);
  while (millis () < 5000) {
    for (int i = 0; i < 3; i++){
      int val = analogRead (sensor[i]);
      minVal[i] = min (val, minVal[i]);
      maxVal[i] = max (val, maxVal[i]);
      threshold[i] = (maxVal[i] + minVal[i]) /2;
    }
  }
}

void loop() {
  if (lineFollowTrue)
    linesensor();
  else if (btSerial.available()) {
    char input = btSerial.read();
    startTime = millis();
    if (input == 'W') {
      digitalWrite (IN_1_LEFT, HIGH);
      digitalWrite (IN_2_LEFT, LOW);
      analogWrite (EN_A_LEFT, 170);
      digitalWrite (IN_3_RIGHT, HIGH);
      digitalWrite (IN_4_RIGHT, LOW);
      analogWrite (EN_B_RIGHT, 170);
    }
    else if(input == 'S') {
      digitalWrite (IN_1_LEFT, LOW);
      digitalWrite (IN_2_LEFT, HIGH);
      analogWrite (EN_A_LEFT, 170);
      digitalWrite (IN_3_RIGHT, LOW);
      digitalWrite (IN_4_RIGHT, HIGH);
      analogWrite (EN_B_RIGHT, 170); 
    }
    else if(input == 'A') {
      digitalWrite (IN_1_LEFT, LOW);
      digitalWrite (IN_2_LEFT, HIGH);
      analogWrite (EN_A_LEFT, 0);
      digitalWrite (IN_3_RIGHT, HIGH);
      digitalWrite (IN_4_RIGHT, LOW);
      analogWrite (EN_B_RIGHT, 150);
    }
    else if(input == 'D') {
      digitalWrite (IN_1_LEFT, HIGH);
      digitalWrite (IN_2_LEFT, LOW);
      analogWrite (EN_A_LEFT, 150);
      digitalWrite (IN_3_RIGHT, LOW);
      digitalWrite (IN_4_RIGHT, HIGH);
      analogWrite (EN_B_RIGHT, 0);
    }
    else if(input == 'I') {
      teta=teta+10;
      teta=constrain(teta,60,180);
      myServo.write(teta);
    }
    else if(input == 'M') {
      teta=teta-10;
      teta=constrain(teta,60,180);
      myServo.write(teta);
    }
    else if(input == 'Y') {
      lineFollowTrue = true;
//        int start = 0;
        
//          if(btSerial.available()) start = 1;        
    }
  }
  else if(millis() - startTime >= 100){
      digitalWrite (IN_1_LEFT, LOW);
      digitalWrite (IN_2_LEFT, LOW);
      analogWrite (EN_A_LEFT, 0);
      digitalWrite (IN_3_RIGHT, HIGH);
      digitalWrite (IN_4_RIGHT, HIGH);
      analogWrite (EN_B_RIGHT, 0);
  }
}
