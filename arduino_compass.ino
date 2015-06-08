//
// arduino_compass.ino
// Description: Arduino Compass - HM55B

const int ENABLE_PIN = 2;
const int CLOCK_PIN  = 3;
const int DATA_PIN   = 4;

const byte COMMAND_LENGTH    = 4;
const byte RESET_COMMAND     = B0000;
const byte MEASURE_COMMAND   = B1000;
const byte READ_DATA_COMMAND = B1100;
const byte MEASUREMENT_READY = B1100;

int angle;

void setup() {
  Serial.begin(9600);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
  reset();
}

void loop() {
  startMeasurement();
  delay(40);
  if (readStatus() == MEASUREMEN_READY) {
    angle = readMeasurement();
    Serial.print("Angle = ");
    Serial.println(angle);
  }
  delay(100);
}

void reset() {
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  serialOut(RESET_COMMAND, COMMAND_LENGTH);
  digitalWrite(ENABLE_PIN, HIGH);
}

int readStatus() {
  int result = 0;
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  serialOut(READ_DATA_COMMAND, COMMAND_LENGTH)
  result = serialIn(4);
  return result;
}

int readMeasurement() {
  int X_Data = 0;
  int Y_Data = 0;
  int calcAngle = 0;
  X_Data = serialIn(11);
  Y_Data = serialIn(11);
  digitalWrite(ENABLE_PIN, HIGH);
  calcAngle = atan2(-Y_Data, X_data) /M_PI *180;
  if (calcAngle < 0) {
    calcAngle = calcAngle + 360;
  }
  return calcAngle;
}

void serialOut(int value,  int numberOfBits) {
  for (int i = numberOfBits; i > 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);
    if (bitRead(value, i-1) ==1) {
      digitalWrite(DATA_PIN, HIGH);
    } else {
      digitalWrite(DATA_PIN, LOW);
    }
    digitalWrite(CLOCK_PIN, HIGH);
  }
}

int serialIn(int numberOfBits) {
  int result = 0;

  pinMode(DATA_PIN, INPUT);
  for (int i = numberOfBits; i > 0; i--) {
    digitalWrite(CLOCK_PIN, HIGH);
    if (digitalRead(DATA_PIN) == HIGH) {
      result = (result << 1) + 1;
    } else {
      result = (result << 1) + 0;
    }
    digitalWrite(CLOCK_PIN, LOW);
  }

  if (bitRead(result, 11) == 1) {
    result = (B11111000 << 8) | result;
  }

  return result;
}
