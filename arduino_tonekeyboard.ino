//
// arduino_tonekeyboard.ino
// Created: 21 Jan 2010
// Modified: 9 Apr 2012
// Author: Tom Igoe
// http://arduino.cc/en/Tutorial/Tone3
// Description: Plays a pitch that changes based on a changing analog input

// Circuit:
// * 3 force-sensing resistors from +5V to analog in 0 through 5
// * 3 10K resistors from analog in 0 through 5 to ground
// * 8-ohm speaker on digital pin 8

#include "pitches.h"

const int threshold = 10;

int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
};

void setup() {
}

void loop() {
  for (int target_sensor = 0; target_sensor < 3; target_sensor++) {
    int sensor_out = analogRead(target_sensor);

    if (sensor_out > threshold) {
      tone(8, notes[target_sensor], 20);
    }
  }
}
