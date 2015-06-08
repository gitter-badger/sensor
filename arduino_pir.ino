//
// arduino_pir.ino
// Description: Arduino Passive Infrared (PIR) Sensor Node

const int LED_PIN = 13
const int PIR_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  int val = digitalRead(PIR_PIN);

  if (val == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
  }
}

