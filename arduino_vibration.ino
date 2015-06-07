//
// arduino_vibration.ino
// Description: Arduino Piezo Sensor Node (vibration)

const int sensorPin = 0;
const int ledPin = 13;
const int THRESHOLD = 100;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int val = analogRead(sensorPin);
  if (val >= THRESHOLD) {
    digitalWrite(ledPin, HIGH);
    delay(100);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
