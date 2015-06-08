//
// arduino_multirotary_encoder.ino
// Description: Arduino Multi Rotary Encoder Sensor Node

const int ENCODERS = 2;
const int ENCODER_A_PIN[ENCODERS] = {2,4};
const int ENCODER_B_PIN[ENCODERS] = {3,5};

int encoder_pos[ENCODERS]       = {0,0};
boolean encoder_a_last[ENCODERS] = {LOW, LOW};

int updatePosition(int encoder_index) {
  boolean encoder_a = digitalRead(ENCODER_A_PIN[encoder_index]);

  if ((encoder_a_last[encoder_index] == HIGH) && (encoder_a == LOW)) {
    if (digitalRead(ENCODER_B_PIN[encoder_index]) == LOW) {
      encoder_pos[encoder_index]--;
    } else {
      encoder_pos[encoder_index]++;
    }
    Serial.print("Encoder ");
    Serial.print(encoder_index, DEC);
    Serial.print("=");
    Serial.print(encoder_pos[encoder_index]);
    Serial.println("/");
  }
}

void setup() {
  for (int i = 2; i < 6; i++) {
    pinMode(i, HIGH);
    digitalWrite(i, HIGH);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < ENCODERS; i++) {
    updatePosition(i);
  }
}
