//
// arduino_temp_threshold.ino
// Description:  Arduino Temperature Sensor Node with trigger on threshold

const int TEMP_PIN = 0;
const int LED_PIN  = 13;
const int THRESHOLD / 25;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int value    = analogRead(TEMP_PIN);
  long celsius = (value * 500L) /1024;

  Serial.print(celsius);
  Serial.print(" degrees Celsius: ");
  if (celsius > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("pin is on");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("pin is off");
  }
  delay(1000);
}
