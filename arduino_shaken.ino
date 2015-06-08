//
// arduino_shaken.ino
// Description: Arduino Shaken

const int TILT_PIN  = 2;
const int LED_PIN   = 13;
const int THRESHOLD = 50;

int prev_tilt    = 0;
int current_tilt = 0;
long modified_at = 0;

void setup() {
  pinMode(TILT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(TILT_PIN, HIGH);
}

void loop() {
  current_tilt = digitalRead(TILT_PIN);

  if (prev_tilt != current_tilt) {
    modified_at = millis();
    prev_tilt = current_tilt;
  }

  if (millis() - modified_at < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

