/**
  Arduino Seismometer Sensor Node using MMA7361 
**/

int ST = 6;
int GSEL = 7;
int ZeroGD = 8;
int SLP = 9;

int Xaxis_pin = 2;
int Yaxis_pin = 1;
int Zaxis_pin = 0;

void setup() {
  Serial.begin(57600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  digitalWrite(SLP, HIGH);
  digitalWrite(GSEL, LOW);
}

void loop() {
  char temp[15];
  sprintf(temp, "%d,%d,%d", analogRead(Xaxis_pin), analogRead(Zaxis_pin));
  Serial.println(temp);
  delay(5);
}
