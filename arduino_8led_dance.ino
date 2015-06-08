//
// arduino_8led_dance.ino
// Description: Make eight LEDs dance. Dance LEDs, dance!

const int LED_PINS[] = {2,3,4,5,6,7,8,9};

void setup() {
  int index;

  for (index = 0; index <= 7; index++) {
    pinMode(LED_PINS[index], OUTPUT);
  }
}

void loop() {
  one_after_another_no_loop(); // Light up all the LEDs in turn
  //one_after_another_loop();  // Same as one_after_another_no_loop, with loop
  //one_on_at_a_time();        // Turn on one LED at a time
  //ping_pong();               // Light the LEDs middle to the edges
  //marquee();                 // Chase lights like you see on signs
  //random_led();              // Blink LEDs randomly
}

void one_after_another_no_loop() {
  int delayTime = 100;

  // turn all the LEDs on:
  digitalWrite(LED_PINS[0], HIGH);  //Turns on LED #0 (pin 2)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[1], HIGH);  //Turns on LED #1 (pin 3)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[2], HIGH);  //Turns on LED #2 (pin 4)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[3], HIGH);  //Turns on LED #3 (pin 5)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[4], HIGH);  //Turns on LED #4 (pin 6)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[5], HIGH);  //Turns on LED #5 (pin 7)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[6], HIGH);  //Turns on LED #6 (pin 8)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[7], HIGH);  //Turns on LED #7 (pin 9)
  delay(delayTime);                //wait delayTime milliseconds

  // turn all the LEDs off:
  digitalWrite(LED_PINS[7], LOW);   //Turn off LED #7 (pin 9)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[6], LOW);   //Turn off LED #6 (pin 8)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[5], LOW);   //Turn off LED #5 (pin 7)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[4], LOW);   //Turn off LED #4 (pin 6)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[3], LOW);   //Turn off LED #3 (pin 5)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[2], LOW);   //Turn off LED #2 (pin 4)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[1], LOW);   //Turn off LED #1 (pin 3)
  delay(delayTime);                //wait delayTime milliseconds
  digitalWrite(LED_PINS[0], LOW);   //Turn off LED #0 (pin 2)
  delay(delayTime);                //wait delayTime milliseconds
}

void one_after_another_loop() {
  int index;
  int delayTime = 100;

  // Turn all the LEDs on:
  for(index = 0; index <= 7; index++) {
    digitalWrite(LED_PINS[index], HIGH);
    delay(delayTime);
  }

  // Turn all the LEDs off:
  for(index = 7; index >= 0; index--) {
    digitalWrite(LED_PINS[index], LOW);
    delay(delayTime);
  }
}

void one_on_at_a_time() {
  int index;
  int delayTime = 100;

  // step through the LEDs, from 0 to 7
  for(index = 0; index <= 7; index++) {
    digitalWrite(LED_PINS[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(LED_PINS[index], LOW);   // turn LED off
  }
}


void ping_pong() {
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                       // make this smaller for faster switching

  // step through the LEDs, from 0 to 7
  for(index = 0; index <= 7; index++) {
    digitalWrite(LED_PINS[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(LED_PINS[index], LOW);   // turn LED off
  }

  // step through the LEDs, from 7 to 0
  for(index = 7; index >= 0; index--) {
    digitalWrite(LED_PINS[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(LED_PINS[index], LOW);   // turn LED off
  }
}

void marquee() {
  int index;
  int delayTime = 200;

  // Step through the first four LEDs
  for(index = 0; index <= 3; index++) {
    digitalWrite(LED_PINS[index], HIGH);    // Turn a LED on
    digitalWrite(LED_PINS[index+4], HIGH);  // Skip four, and turn that LED on
    delay(delayTime);                      // Pause to slow down the sequence
    digitalWrite(LED_PINS[index], LOW);     // Turn the LED off
    digitalWrite(LED_PINS[index+4], LOW);   // Skip four, and turn that LED off
  }
}


void random_led() {
  int index;
  int delayTime;

  index = random(8);
  delayTime = 100;

  digitalWrite(LED_PINS[index], HIGH);  // turn LED on
  delay(delayTime);                    // pause to slow down
  digitalWrite(LED_PINS[index], LOW);   // turn LED off
}
