//
// arduino_tonemelody.ino
// Created 21 Jan 2010
// Modified 30 Aug 2011
// Author: Tom Igoe
// http://arduino.cc/en/Tutorial/Tone
// Description: Plays a melody

// Circuit:
// * 8-ohm speaker on digital pin 8

#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int note_durations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  for (int target_note = 0; target_note < 8; target_note++) {
    int duration = 1000 / note_durations[target_note];
    int pause    = duration * 1.30;

    tone(8, melody[target_note], duration);
    delay(pause);
    noTone(8);
  }
}

void loop() {
}
