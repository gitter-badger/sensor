//
// arduino_digitalreadserial.ino
// Description: Reads digital input from pin 2, print result to serial monitor.

const int BUTTON_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  Serial.println(buttonState);
  delay(1);
}