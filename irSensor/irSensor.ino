//---------------------IR SENSOR----------------------//
// LED pin on digital pin 13
//const int LED_PIN = 13; //internal LED
//const int LED_PIN2 = 2; //external LED
// IR pin connected to digital pin 7
const int IR_PIN = 13;

void setup() {
  Serial.begin (9600);  
  //initialize LED_PIN as output
//  pinMode (LED_PIN, OUTPUT);
//  pinMode (LED_PIN2, OUTPUT);
  //initialize IR_PIN as input
  pinMode (IR_PIN, INPUT);
}

void loop() {
  //read IR sensor state (HIGH or LOW)
  int irState = digitalRead (IR_PIN);
  // write the reverse of the IR state to LED
  Serial.println(irState);
  //Serial.println(!irState);
//  digitalWrite (LED_PIN2, !irState);
//  digitalWrite (LED_PIN, !irState);
}
