// ----------------- CONTROLLING MOTOR WITH L298N ----------------- //
const int EN_A_LEFT = 6;
const int IN_1_LEFT = 8;
const int IN_2_LEFT = 7;
const int EN_B_RIGHT = 5;
const int IN_3_RIGHT = 4;
const int IN_4_RIGHT = 2;

void forward (int pwmLeft, int pwmRight) {
  digitalWrite (IN_1_LEFT, HIGH);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, LOW);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void backward (int pwmLeft, int pwmRight) {
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, HIGH);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, LOW);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void left (int pwmLeft, int pwmRight) {
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, HIGH);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, LOW);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void right (int pwmLeft, int pwmRight) {
  digitalWrite (IN_1_LEFT, HIGH);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, LOW);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void stopp () {
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, 0);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, 0);
}

void setup() {
  pinMode (EN_A_LEFT, OUTPUT);
  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  pinMode (EN_B_RIGHT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
}

void loop() {
  forward (255,255);
  delay(3000);
  backward (255,255);
  delay(3000);
  left (0,255);
  delay (3000);
  right (255,0);
  delay(3000);
  stopp ();
  delay (2000);
}
