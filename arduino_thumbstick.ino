//
// arduino_thumbstick.ino
// Author: Mike Grusin
// Description: Thumb Joystick with two potentiometers - COM-09032

const int VERT_PIN  = 0;
const int HORIZ_PIN = 1;
const int SEL_PIN   = 2;

void setup() {
  pinMode(SEL_PIN, INPUT_PULLUP);

  digitalWrite(SEL_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  int vertical, horizontal, select;

  vertical   = analogRead(VERT_PIN);
  horizontal = analogRead(HORIZ_PIN);
  select     = digitalRead(SEL_PIN);

  Serial.print("vertical: ");
  Serial.print(vertical, DEC);
  Serial.print(" horizontal: ");
  Serial.print(horizontal, DEC);
  Serial.print(" select: ");
  if(select == HIGH)
    Serial.println("not pressed");
  else
    Serial.println("PRESSED!");
}
