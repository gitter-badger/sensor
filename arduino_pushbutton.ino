//
// arduino_pushbutton.ino
// Description: On press of push button, power on LED

const int BUTTON_PIN = 2;
const int LED_PIN    = 13;

int buttonState = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}