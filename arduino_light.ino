//
// arduino_light.ino
// Description: Arduino Light Dependent Resister (LDR) Sensor Node

const int LED_PIN = 13;
const int LDR_PIN = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int rate = analogRead(LDR_PIN);

  digitalWrite(LED_PIN, HIGH);
  delay(rate);
  digitalWrite(LED_PIN, LOW);
  delay(rate);
}
