//
// arduino_blink_nodelay.ino
// Description: Blink LED without delay()

const int ledPin = 13;
int led_state = LOW;

// unsigned long great for variables of time
unsigned long prev_millis = 0;
const long interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // >> Your code here

  unsigned long currentMillis = millis();

  if (currentMillis - prev_millis >= interval) {
    prev_millis = currentMillis;

    if (led_state == LOW)
      led_state = HIGH;
    else
      led_state = LOW;

    digitalWrite(ledPin, led_state);
  }
}

