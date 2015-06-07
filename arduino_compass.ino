//
// arduino_compass.ino
// Description:  Arduino Compass Sensor Node HM55B

const int enablePin = 2;
const int clockPin = 3;
const int dataPin = 4;

const byte COMMAND_LENGTH = 4;
const byte RESET_COMMAND = B0000;
const byte MEASURE_COMMAND = B1000;
const byte READ_DATA_COMMAND = B1100;
const byte MEASUREMENT_READY = B1100;

int angle;

void setup() {
  Serial.begin(9600);
  pinMode(enablePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);
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
  pinMode(dataPin, OUTPUT);
  digitalWrite(enablePin, LOW);
  serialOut(RESET_COMMAND, COMMAND_LENGTH);
  digitalWrite(enablePin, HIGH);
}

int readStatus() {
  int result = 0;
  pinMode(dataPin, OUTPUT);
  digitalWrite(enablePin, LOW);
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
  digitalWrite(enablePin, HIGH);
  calcAngle = atan2(-Y_Data, X_data) /M_PI *180;
  if (calcAngle < 0) {
    calcAngle = calcAngle + 360;
  }
  return calcAngle;
}

void serialOut(int value,  int numberOfBits) {
  for (int i = numberOfBits; i > 0; i--) {
    digitalWrite(clockPin, LOW);
    if (bitRead(value, i-1) ==1) {
      digitalWrite(dataPin, HIGH);
    } else {
      digitalWrite(dataPin, LOW);
    }
    digitalWrite(clockPin, HIGH);
  }
}

int serialIn(int numberOfBits) {
  int result = 0;

  pinMode(dataPin, INPUT);
  for (int i = numberOfBits; i > 0; i--) {
    digitalWrite(clockPin, HIGH);
    if (digitalRead(dataPin) == HIGH) {
      result = (result << 1) + 1;
    } else {
      result = (result << 1) + 0;
    }
    digitalWrite(clockPin, LOW);
  }

  if (bitRead(result, 11) == 1) {
    result = (B11111000 << 8) | result;
  }

  return result;
}
