/**
  Arduino Infrared Sensor Node (distance)
**/

const int ledPin = 13;
const int sensorpin = 0;

const long referenceMv = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int val = analogRead(sensorpin);
  int mV = (val * referenceMv) / 1023;

  Serial.print(mV);
  Serial.print(",");
  int cm = getDistance(mV);
  Serial.println(cm);

  digitalWrite(ledPin, HIGH);
  delay(cm * 10);
  digitalWrite(ledPin, LOW);
  delay(cm * 10);

  delay(100);
}

int getDistance(int mV) {
  if (mV > INTERVAL * TABLE_ENTRIES - 1) {
    return distance[TABLE_ENTRIES - 1];
  } else {
    int index = mV / INTERVAL;
    float frac = (mV % 250) / (float)INTERVAL;
    return distance[index] - ((distance[index] - distanc[index + 1]) * frac);
  }
}
