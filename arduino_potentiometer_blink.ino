//
// arduino_potentiometer_blink.ino
// Description: Potentiometer position adjusts blink rate
// http://learn.sparkfun.com/products/2

int POT_PIN = 0;
int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int pot_value;

  pot_value = analogRead(POT_PIN);

  digitalWrite(LED_PIN, HIGH);
  delay(pot_value);
  digitalWrite(LED_PIN, LOW);
  delay(pot_value);
}
