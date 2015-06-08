//
// arduino_fade.ino
// Description: Fade an LED

const int LED_PIN = 9;

int brightness  = 0;
int fade_effect = 5;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, brightness);

  brightness = brightness + fade_effect;

  if (brightness == 0 || brightness == 255) {
    fade_effect = -fade_effect ;
  }

  delay(30);
}

