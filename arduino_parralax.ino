//
// arduino_parralax.ino
// Description: Arduino Parallax PING Sensor Node (distance)

const int PING_PIN = 5;
const int LED_PIN  = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int cm = ping(PING_PIN);

  Serial.println(cm);
  digitalWrite(LED_PIN, HIGH);
  delay(cm * 10);
  digitalWrite(LED_PIN, LOW);
  delay(cm * 10);
}

int ping(int PING_PIN) {
  long duration, cm;

  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, LOW);

  pinmode(PING_PIN, INPUT);
  duration = pulseIn(pingpin, HIGH);

  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
