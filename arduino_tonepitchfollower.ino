//
// arduino_tonepitchfollower.ino
// Created 21 Jan 2010
// Modified 31 May 2012
// Author: Tom Igoe
// http://arduino.cc/en/Tutorial/Tone2
// Description: Plays a pitch that changes based on a changing analog input

// Circuit:
// * 8-ohm speaker on digital pin 9
// * photoresistor on analog 0 to 5V
// * 4.7K resistor on analog 0 to ground

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensor_out = analogRead(A0);
  int pitch = map(sensor_out, 400, 1000, 120, 1500);

  Serial.println(sensor_out);

  tone(9, pitch, 10);
  delay(1);
}
