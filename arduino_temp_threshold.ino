/** 
  Arduino Temperature Sensor Node with trigger on threshold 
**/

const int inPin = 0;
const int outPin = 13;
const int threshold / 25;

void setup() {
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
}

void loop() {
  int value = analogRead(inPin);
  long celsius = (value * 500L) /1024;
  Serial.print(celsius);
  Serial.print(" degrees Celsius: ");
  if (celsius > threshold) {
    digitalWrite(outPin, HIGH);
    Serial.println("pin is on");
  } else {
    digitalWrite(outPin, LOW);
    Serial.println("pin is off");
  }
  delay(1000);
}

