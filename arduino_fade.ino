//
// arduino_fade.ino
// Description: Fade an LED

int ledPin = 9;
int brightness = 0;
int fade_effect = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);

  brightness = brightness + fade_effect;

  if (brightness == 0 || brightness == 255) {
    fade_effect = -fade_effect ;
  }

  delay(30);
}

