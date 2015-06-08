//
// arduino_vibration.ino
// Description: Arduino Piezo Sensor Node (vibration)

const int PIEZO_PIN = 0;
const int LED_PIN   = 13;
const int THRESHOLD = 100;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int val = analogRead(PIEZO_PIN);
  if (val >= THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
