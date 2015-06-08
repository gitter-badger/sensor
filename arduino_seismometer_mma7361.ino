//
// arduino_seismometer_mma7361.ino
// Description: Arduino Seismometer using MMA7361

const int X_AXIS_PIN = 2;
const int Y_AXIS_PIN = 1;
const int Z_AXIS_PIN = 0;

const int ST     = 6;
const int GSEL   = 7;
const int ZeroGD = 8;
const int SLP    = 9;

void setup() {
  Serial.begin(57600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  digitalWrite(SLP, HIGH);
  digitalWrite(GSEL, LOW);
}

void loop() {
  char temp[15];
  sprintf(temp, "%d,%d,%d", analogRead(X_AXIS_PIN), analogRead(Z_AXIS_PIN));
  Serial.println(temp);
  delay(5);
}
