//
// arduino_seismometer_kxm52.ino
// Description: Arduino Seismometer using KXM52

int Xaxis_pin = 3;
int Yaxis_pin = 4;
int Zaxis_pin = 5;

void setup() {
  Serial.begin(57600);
}

void loop() {
  char temp[15];
  sprintf(temp, "%d,%d,%d", analogRead(Yaxis_pin), analogRead(Zaxis_pin));
  Serial.println(temp);
  delay(50);
}
