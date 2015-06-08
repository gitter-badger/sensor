//
// arduino_temp_lm35.ino
// Description: Arduino Temperature using LM35

const int LM35_PIN = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(LM35_PIN);

  Serial.print(value); Serial.print(" > ");

  float millivolts = (value / 1024.0) * 5000;
  float celsius = millivolts / 10;

  Serial.print(celsius);
  Serial.print(" degrees Celsius, ");
  Serial.print( (celsius * 9)/ 5 + 32);
  Serial.println(" degrees Fahrenheit");
  delay(1000);
}
