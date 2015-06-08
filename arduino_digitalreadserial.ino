//
// arduino_digitalreadserial.ino
// Description: Reads digital input from pin 2, print result to serial monitor.

int pushButton = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);

  Serial.println(buttonState);

  delay(1);
}