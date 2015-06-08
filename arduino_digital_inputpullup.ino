//
// arduino_digital_inputpullup.ino
// Description: demonstrate use of pinMode(INPUT_PULLUP)

const int pushButtonPin = 2;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);

  pinMode(pushButtonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(pushButtonPin);

  Serial.println(sensorVal);

  // Pullup mode means the pushbutton's logic is inverted
  if (sensorVal == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
