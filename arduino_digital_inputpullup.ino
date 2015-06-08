//
// arduino_digital_inputpullup.ino
// Description: demonstrate use of pinMode(INPUT_PULLUP)

const int BUTTON_PIN = 2;
const int LED_PIN    = 13;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(BUTTON_PIN);

  Serial.println(sensorVal);

  // Pullup mode means the pushbutton's logic is inverted
  if (sensorVal == HIGH) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
}
