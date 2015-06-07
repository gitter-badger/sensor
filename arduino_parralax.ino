//
// arduino_parralax.ino
// Description: Arduino Parallax PING Sensor Node (distance)

const int pingPin = 5;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int cm = ping(pingPin);
  Serial.println(cm);
  digitalWrite(ledPin, HIGH);
  delay(cm * 10);
  digitalWrite(ledPin, LOW);
  delay(cm * 10);
}

int ping(int pingPin) {
  long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinmode(pingPin, INPUT);
  duration = pulseIn(pingpin, HIGH);

  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
