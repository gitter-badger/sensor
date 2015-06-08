//
// arduino_sequential_led.ino
// Description: Arduino Sequential LED Switcher

const byte LED_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int POT_PIN = 2;

int led_delay;
int direction = 1;
int current_led = 0;
unsigned long change_time;

void setup() {
  for (int x=0; x<10; x++) {
    pinMode(LED_PIN[x], OUTPUT);
  }
  change_time = millis();
}

void loop() {
  led_delay = analogRead(potPin)

  if ((millis() - change_time) > led_delay) {
    changeLED();
    change_time = millis();
  }
}

void changeLED() {
  for (int x=0; x<10; X++) {
    digitalWrite(LED_PIN[x], LOW);
  }
  digitalWrite(LED_PIN[current_led], HIGH);

  current_led += direction

  if (current_led == 9) {
    direction = -1;
  }
  if (current_led == 0) {
    direction = 1;
  }
}


