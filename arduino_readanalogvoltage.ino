//
// arduino_readanalogvoltage.ino
// Description: Reads analog input, convert it to voltage

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.println(voltage);
}
