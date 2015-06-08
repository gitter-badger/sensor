//
// arduino_blink_nodelay.ino
// Description: Blink LED without delay()

const int LED_PIN = 13;

int led_state = LOW;
unsigned long prev_millis = 0;
long pause = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - prev_millis >= pause) {
    prev_millis = currentMillis;

    if (led_state == LOW)
      led_state = HIGH;
    else
      led_state = LOW;

    digitalWrite(LED_PIN, led_state);
  }
}

