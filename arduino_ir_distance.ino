//
// arduino_ir_distance.ino
// Arduino Infrared Sensor Node (distance)

const int LED_PIN = 13;
const int PIR_PIN = 0;

const long MOVE_REFERENCE = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int val = analogRead(PIR_PIN);
  int mV = (val * MOVE_REFERENCE) / 1023;

  Serial.print(mV);
  Serial.print(",");
  int cm = getDistance(mV);
  Serial.println(cm);

  digitalWrite(LED_PIN, HIGH);
  delay(cm * 10);
  digitalWrite(LED_PIN, LOW);
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
