#include <Servo.h>
const int A = 3;
const int B = 4;
const int C = 5;
const int D = 6;
const int E = 7;
const int F = 8;
const int G = 9;
const int LED1 = 10;
const int LED2 = 2;
const int IR = 12;
const int BZR =11;
const int BTN =13;
const int SERVO=A0;
Servo myservo;
int ctr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(IR, INPUT);
  pinMode(BZR, OUTPUT);
  pinMode(BTN, INPUT);
  myservo.attach(SERVO);
  
//  pinMode (2,OUTPUT);
}

void zero() {
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, LOW);
}
void one() {
  digitalWrite (A, LOW);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
}
void two() {
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, LOW);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, LOW);
  digitalWrite (G, HIGH);
}
void three() {
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, HIGH);
}
void four() {
  digitalWrite (A, LOW);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
}
void five() {
  digitalWrite (A, HIGH);
  digitalWrite (B, LOW);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, LOW);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
}
void six() {
  digitalWrite (A, HIGH);
  digitalWrite (B, LOW);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
}
void seven() {
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
}
void eight() {
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
}
void nine() {
  digitalWrite (A, HIGH);
  digitalWrite (B, HIGH);
  digitalWrite (C, HIGH);
  digitalWrite (D, HIGH);
  digitalWrite (E, LOW);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
}
void full() {
  digitalWrite (A, HIGH);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
  analogWrite(BZR,225);
}

void loop() {
//  Serial.println(digitalRead(IR));
//  Serial.println(ctr);
  myservo.write(0);
  digitalWrite(LED1,HIGH);
  if(!digitalRead(BTN)) {
    ctr=0;
  }
  while(ctr>9){
    full();
    if(!digitalRead(BTN)) ctr=0;
  }
  if(!digitalRead(IR)) {
    digitalWrite(LED2,HIGH),myservo.write(100),analogWrite(BZR, 125),ctr++;
    delay(500);
    myservo.write(0);
  }
  else {
    digitalWrite(LED2,LOW),analogWrite(BZR, 0);    
  }
  
  if(ctr==0) zero();
  else if(ctr==1) one();
  else if(ctr==2) two();
  else if(ctr==3) three();
  else if(ctr==4) four();
  else if(ctr==5) five();
  else if(ctr==6) six();
  else if(ctr==7) seven();
  else if(ctr==8) eight();
  else nine();
  delay(500);
}
