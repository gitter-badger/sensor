//
// arduino_tilt.ino
// Description: Arduino Tilt Sensor Node

const int tiltSensorPin = 2;
const int firstLEDPin = 11;
const int secondLEDPin = 12;

void setup() {
  pinMode (tiltSensorPin, INPUT);
  digitalWrite(tiltSensorPin, HIGH);

  pinMode(firstLEDPin, OUTPUT);
  pinMode(secondLEDPin, OUTPUT);
}

void loop() {
  if (digitalRead(tiltSensorPin) {
    digitalWrite(firstLEDPin, HIGH);
    digitalWrite(secondLEDPin, LOW);
  } else {
    digitalWrite(firstLEDPin, LOW);
    digitalWrite(secondLEDPin, HIGH);
  }
}

