//
// arduino_flex_servo.ino
// Description: Use the "flex sensor" to change the position of a servo.
// Circuit:
//    Flex sensor:
//      Connect one of the pins to ANALOG IN pin 0 on the Arduino.
//      Connect the same pin,
//        through a 10K Ohm resistor (brown black orange) to GND.
//      Connect the other pin to 5V.
//
//    Servo:
//      Connect the RED wire (power) to 5 Volts (5V)
//      Connect the WHITE wire (signal) to digital pin 9
//      Connect the BLACK wire (ground) to ground (GND)

#include <Servo.h>

Servo servo1;

const int FLEX_PIN  = 0;
const int MAX_RANGE = 900;
const int MIN_RANGE = 600;
// HINT Use serial monitor to adjust max and min values

void setup() {
  servo1.attach(9);
  Serial.begin(9600);
}

void loop() {
  int flex_position;
  int servo_position;

  flex_position  = analogRead(FLEX_PIN);
  servo_position = map(flex_position, MIN_RANGE, MAX_RANGE, 0, 180);
  servo_position = constrain(servo_position, 0, 180);

  servo1.write(servo_position);

  Serial.print("sensor: ");
  Serial.print(flex_position);
  Serial.print("  servo: ");
  Serial.println(servo_position);
  delay(20);
}
