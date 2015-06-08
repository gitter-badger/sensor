//
// arduino_rotary_encoder.ino
// Description: Arduino Rotary Encoder

const int ENCODER_A_PIN = 4;
const int ENCODER_B_PIN = 2;
const int STEP_RATE     = 16;

int val;
int angle = 0;
int encoderPos = 0;

boolean encoder_a_last = LOW;

void setup() {
  pinMode(ENCODER_A_PIN, INPUT);
  pinMode(ENCODER_B_PIN, INPUT);

  digitalWrite(ENCODER_A_PIN, HIGH);
  digitalWrite(ENCODER_B_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  boolean encoderA = digitalRead(ENCODER_A_PIN);

  if ((encoder_a_last == HIGH) && (encoderA == LOW)) {
    if (digitalRead(ENCODER_B_PIN) == LOW) {
      encoderPos--;
    } else {
      encoderPos++;
    }

    angle = (encoderPos % STEP_RATE) * 360 / STEP_RATE;
    Serial.print(encoderPos);
    Serial.print(" ");
    Serial.println(angle);
  }

  encoder_a_last = encoderA;
}
