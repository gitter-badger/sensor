//
// arduino_rfid_reader.ino
// Description: Arduino RFID Reader Sensor Node

const int RFID_PIN = 2
const int START_BYTE   = 10;
const int END_BYTE     = 13;
const int TAG_LENGTH   = 10;
const int TOTAL_LENGTH = TAG_LENGTH + 2;

char tag[TAG_LENGTH + 1];
int bytesread = 0;

void setup() {
  Serial.begin(2400);
  pinMode(RFID_PIN, OUTPUT);
  digitalWrite(RFID_PIN, LOW);
}

void loop() {
  if (Serial.available() >= TOTAL_LENGTH) {
    if (Serial.read() == START_BYTE) {
      bytesread = 0;

      while (bytesread < TAG_LENGTH) {
        int val = Serial.read();

        if ((val == START_BYTE) || (val == END_BYTE)) {
          break;

        tag[bytesread] = val;
        bytesread      = bytesread + 1;
      }

      if (Serial.read() == END_BYTE) {
        tag[bytesread] = 0;

        Serial.print("RFID tag is: ");
        Serial.println(tag);
      }
    }
  }
}
