//
// arduino_pir.ino
// Description: Arduino Passive Infrared (PIR) Sensor Node

const int ledPin = 13
const int inputPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputpin, INPUT);
}

void loop() {
  int val = digitalRead(inputPin);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledpPin, LOW);
  }
}

