//---------POTENTIOMETER----------//
//potetiometer connected to analog pin A0
const int POT_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //initialize POT_PIN as input
  pinMode (POT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead (POT_PIN);

  //print the input value
  Serial.println (potVal);
}
