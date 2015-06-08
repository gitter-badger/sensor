//
// arduino_debounce.ino
// Description: On button push, toggle LED based on previous state.

const int BUTTON_PIN = 2;
const int LED_PIN    = 13;

int button_state;
int curent_led_state = HIGH;
int last_led_state   = LOW;

long last_debounce_time = 0;
long debounce_delay     = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, curent_led_state);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != last_led_state) {
    last_debounce_time = millis();
  }

  if ((millis() - last_debounce_time) > debounce_delay) {
    if (reading != button_state) {
      button_state = reading;

      if (button_state == HIGH) {
        curent_led_state = !curent_led_state;
      }
    }
  }

  digitalWrite(LED_PIN, curent_led_state);

  last_led_state = reading;
}

