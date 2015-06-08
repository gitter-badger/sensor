//
// arduino_seismometer_kxm52.ino
// Description: Arduino Seismometer - KXM52

int X_AXIS_PIN = 3;
int Y_AXIS_PIN = 4;
int Z_AXIS_PIN = 5;

void setup() {
  Serial.begin(57600);
}

void loop() {
  char temp[15];

  sprintf(temp, "%d,%d,%d", analogRead(Y_AXIS_PIN), analogRead(Z_AXIS_PIN));
  Serial.println(temp);
  delay(50);
}
