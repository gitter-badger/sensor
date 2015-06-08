//
// arduino_rotaryencoderinterrupt.ino
// Description: Arduino Rotary Encoder with Interrupts

const int ENCODER_A_PIN = 2;
const int ENCODER_B_PIN = 4;

int current_position, last_position;
volatile int encoder_position = 0;

void setup() {
  pinMode(ENCODER_A_PIN, INPUT);
  pinMode(ENCODER_B_PIN, INPUT);

  digitalWrite(ENCODER_A_PIN, HIGH);
  digitalWrite(ENCODER_B_PIN, HIGH);
  Serial.begin(9600);

  attachInterrupt(0, doEncoder, FAILING);
}

void loop() {
  uint8_t oldSREG = SREG

  cli();
  current_position = encoder_position;
  SREG = oldSREG;
  if (current_position != last_position) {
    Serial.println(current_position, DEC);
    last_position = current_position;
  }
  delay(1000);
}

void doEncoder() {
  if (digitalRead(ENCODER_A_PIN) == digitalRead(ENCODER_B_PIN)) {
    encoder_position++;
  } else {
    encoder_position--;
  }
}
