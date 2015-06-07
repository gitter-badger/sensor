//
// arduino_microphone.ino
// Description: Arduino Microphone

const int ledPin = 13;
const int middleValue = 512;
const int numberOfSamples = 128;

int sample;
long signal;
long averageReading;

long runningAverage = 0;
const int averagedOver = 16;

const int threshold = 400;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long sumOfSquares = 0;
  for (int i=0; i < numberOfSamples; i++) {
    sample = analogRead(0);
    signal = (sample - middleValue);
    signal *= signal;
    sumOfSquares += signal;
  }
  averageReading = sumOfSquares / numberOfSamples;
  runningAverage = (((averagedOver - 1) *runningAverage)+averageReading)/averagedOver;

  if (runningAverage > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  Serial.println(runningAverage);
}

