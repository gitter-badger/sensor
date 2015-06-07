//
// arduino_multirotary_encoder.ino
// Description: Arduino Multi Rotary Encoder Sensor Node

const int ENCODERS = 2;
const int encoderPinA[ENCODERS] = {2,4};
const int encoderPinB[ENCODERS] = {3,5};
int encoderPos[ENCODERS] = {0,0};
boolean encoderALast[ENCODERS] = {LOW, LOW};

void setup() {
  for (int i=2; i<6; i++) {
    pinMode(i, HIGH);
    digitalWrite(i, HIGH);
  }
  Serial.begin(9600);
}

int updatePosition(int encoderIndex) {
  boolean encoderA = digitalRead(encoderPinA[encoderIndex]);
  if ((encoderALast[encoderIndex] == HIGH) && (encoderA == LOW)) {
    if (digitalRead(encoderPinB[encoderIndex]) == LOW) {
      encoderPos[encoderIndex]--;
    } else {
      encoderPos[encoderIndex]++;
    }
    Serial.print("Encoder ");
    Serial.print(encoderIndex, DEC);
    Serial.print("=");
    Serial.print(encoderPos[encoderIndex]);
    Serial.println("/");
  }
}

void loop() {
  for (int i=0; i < ENCODERS; i++) {
    updatePosition(i);
  }
}
