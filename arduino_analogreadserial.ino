//
// arduino_analogreadserial.ino
// Description: Read analog input from pin 0, print result to serial monitor.

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
  delay(1);
}
