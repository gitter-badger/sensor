//
// arduino_servomotor.ino
// Description: Sweep a servo back and forth (full range).
// Circuit:
//   Connect the RED wire (power) to 5 Volts (5V)
//   Connect the WHITE wire (signal) to digital pin 9
//   Connect the BLACK wire (ground) to ground (GND)

// WARNING servos can use a lot of power, which can cause your
//   Arduino to reset or behave erratically. If you're using large
//   servos or many of them, it's best to provide them with their
//   own separate 5V supply. See this Arduino Forum thread for info:
//   http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1239464763

#include <Servo.h>
// WARNING this library disables PWM on pins 9 and 10!

const int SERVO_1_PIN = 9

Servo servo1;

void setup() {
  servo1.attach(SERVO_1_PIN);
}

void loop() {
  int angle;

  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo1.write(0);
  delay(1000);

  // Go to 180 degrees, stepping by two degrees
  for(angle = 0; angle < 180; angle += 2) {
    servo1.write(angle);
    delay(20);
  }

  // Go to 0 degrees, stepping by one degree
  for(angle = 180; angle >= 0; angle -= 1) {
    servo1.write(angle);
    delay(20);
  }
}
