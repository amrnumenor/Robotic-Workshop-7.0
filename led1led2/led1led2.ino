const int LED_PIN1 = 3;
const int LED_PIN2 = 4;
const int BUTTON_PIN = 2;
int LED_state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);
    
    /*troubleshoot*/
    Serial.println(buttonState);

    if (LED_state == 1) {
      digitalWrite(LED_PIN1, HIGH);
      digitalWrite(LED_PIN2, LOW);
    }
    else if (LED_state == 0){
      digitalWrite(LED_PIN2, HIGH);
      digitalWrite(LED_PIN1, LOW); 
    }
    
    while(!buttonState){
      buttonState = digitalRead(BUTTON_PIN);
      if (buttonState == HIGH) {
        LED_state = !LED_state;
        break;
      }
      delay(10);
    }
}
