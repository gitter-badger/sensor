//
// arduino_tilt.ino
// Description: Arduino Tilt Sensor Node

const int TILT_PIN  = 2;
const int LED_A_PIN = 11;
const int LED_B_PIN = 12;

void setup() {
  pinMode(TILT_PIN, INPUT);
  pinMode(LED_A_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

  digitalWrite(TILT_PIN, HIGH);
}

void loop() {
  if (digitalRead(TILT_PIN) {
    digitalWrite(LED_A_PIN, HIGH);
    digitalWrite(LED_B_PIN, LOW);
  } else {
    digitalWrite(LED_A_PIN, LOW);
    digitalWrite(LED_B_PIN, HIGH);
  }
}

