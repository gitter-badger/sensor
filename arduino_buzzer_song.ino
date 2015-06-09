//
// arduino_buzzer_song.ino
// Author: D. Cuartielles
// Description: Use the buzzer to play a song!
// Circuit:
//   Connect the positive pin to Arduino digital pin 9.
//   (Note that this must be a PWM pin.)
//   Connect the negative pin to GND.

//  note 	frequency
//  c     262 Hz
//  d     294 Hz
//  e     330 Hz
//  f     349 Hz
//  g     392 Hz
//  a     440 Hz
//  b     494 Hz
//  C     523 Hz

const int BUZZER_PIN  = 9;
const int SONG_LENGTH = 18;

char notes[] = "cdfda ag cdfdg gf ";
int beats[]  = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo    = 150;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int i, duration;

  for (i = 0; i < SONG_LENGTH; i++) {
    duration = beats[i] * tempo;

    if (notes[i] == ' ') {
      delay(duration);
    } else {
      tone(BUZZER_PIN, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo/10);
  }

  while(true) {}
}

int frequency(char note) {
  int i;
  const int numNotes = 8;

  char names[]      = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++) {
    if (names[i] == note) {
      return(frequencies[i]);
    }
  }

  return(0);
}
