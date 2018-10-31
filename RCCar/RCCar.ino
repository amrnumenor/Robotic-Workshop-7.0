//---------------------ADRUINO RC--------------------//
#include <SoftwareSerial.h>
#include <Servo.h>
const int RX_PIN = 10;
const int TX_PIN = 11;
const int EN_A_LEFT = 6;
const int IN_1_LEFT = 8;
const int IN_2_LEFT = 7;
const int EN_B_RIGHT = 5;
const int IN_3_RIGHT = 4;
const int IN_4_RIGHT = 2;
const int LDR1 = A0;
const int LDR2 = A1;
const int LDR3 = A2;
const int SERVO = 9;
unsigned long startTime = millis();
Servo myServo;
int teta=180;
int sensor[3] = {A0, A1, A2};
int maxVal [3] = {0,0,0};
int minVal [3] = {1023, 1023, 1023};
int threshold [3];

SoftwareSerial btSerial (RX_PIN, TX_PIN);

void forward (int pwmLeft,int pwmRight) {
  digitalWrite (IN_1_LEFT, HIGH);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, LOW);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void backward(int pwmLeft,int pwmRight) {
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, HIGH);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, LOW);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void left(int pwmLeft,int pwmRight) {
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, HIGH);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, pwmRight);
  analogWrite (EN_B_RIGHT, 200);  
}

void right(int pwmLeft,int pwmRight){
  digitalWrite (IN_1_LEFT, HIGH);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, LOW);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void stopp() {
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, 0);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, 0);
}

void autoMode() {
  bool ldrVal1 = analogRead(LDR1)>threshold[0];
  bool ldrVal2 = analogRead(LDR2)>threshold[1];
  bool ldrVal3 = analogRead(LDR3)>threshold[2];

  static bool turnLeft, turnRight;

  if(ldrVal1) {
    turnLeft = true;
  }

  else if(ldrVal3) {
    turnRight = true; 
  }

  else if(ldrVal2) {
    turnLeft = false, turnRight = false;
  }
  if (turnLeft){
    left(0,120);
  }
  else if(turnRight) {
    right(100,0);
  }
  else forward(110,110);
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
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
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
  if (btSerial.available()) {
    char input = btSerial.read();
    if (input == 'W') {
      forward(170,170);
    }
    else if(input == 'S') {
      backward(170,170); 
    }
    else if(input == 'A') {
      left(0,150);
    }
    else if(input == 'D') {
      right(150,0);
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
      int start =0 ;
      while(start==0) {
        autoMode();
        if(btSerial.available()) start = 1; 
      }
    }
  }
  else if(millis() - startTime >= 100){
    stopp();
  }
}
