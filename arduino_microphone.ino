//
// arduino_microphone.ino
// Description: Arduino Microphone

const int LED_PIN      = 13;
const int MIDDLE_VALUE = 512;
const int SAMPLE_COUNT = 128;
const int AVG_OVER     = 16;
const int THRESHOLD    = 400;

int sample;
long signal;
long averageReading;
long runningAverage = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long sumOfSquares = 0;

  for (int i=0; i < SAMPLE_COUNT; i++) {
    sample = analogRead(0);
    signal = (sample - MIDDLE_VALUE);
    signal *= signal;
    sumOfSquares += signal;
  }

  averageReading = sumOfSquares / SAMPLE_COUNT;
  runningAverage = (((AVG_OVER - 1) *runningAverage)+averageReading)/AVG_OVER;

  if (runningAverage > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  Serial.println(runningAverage);
}

