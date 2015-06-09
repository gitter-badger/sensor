//
// arduino_shift_register_8led.ino
// Description: Convert three pins into eight - 74HC595

const int DATA_PIN  = 2;
const int CLOCK_PIN = 3;
const int LATCH_PIN = 4;

byte data = 0;

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}

void loop() {
  one_after_another();
  //one_on_at_a_time();
  //ping_pong();
  //random_led();
  //marquee();
  //binary_count();
}

void shift_write(int desiredPin, boolean desiredState) {
  bitWrite(data, desiredPin, desiredState);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);
}

void one_after_another() {
  int index;
  int delayTime = 100;

  for(index = 0; index <= 7; index++) {
    shift_write(index, HIGH);
    delay(delayTime);
  }

  for(index = 7; index >= 0; index--) {
    shift_write(index, LOW);
    delay(delayTime);
  }
}

void one_on_at_a_time() {
  int index;
  int delayTime = 100;

  for(index = 0; index <= 7; index++) {
    shift_write(index, HIGH);
    delay(delayTime);
    shift_write(index, LOW);
  }
}

void ping_pong() {
  int index;
  int delayTime = 100;

  for(index = 0; index <= 7; index++) {
    shift_write(index, HIGH);
    delay(delayTime);
    shift_write(index, LOW);
  }

  for(index = 7; index >= 0; index--) {
    shift_write(index, HIGH);
    delay(delayTime);
    shift_write(index, LOW);
  }
}

void random_led() {
  int index;
  int delayTime = 100;

  index = random(8);

  shift_write(index, HIGH);
  delay(delayTime);
  shift_write(index, LOW);
}

void marquee() {
  int index;
  int delayTime = 200;

  for(index = 0; index <= 3; index++) {
    shift_write(index, HIGH);
    shift_write(index+4, HIGH);
    delay(delayTime);
    shift_write(index, LOW);
    shift_write(index+4, LOW);
  }
}

void binary_count() {
  int delayTime = 1000;

  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  data++;
  delay(delayTime);
}
