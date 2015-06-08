//
// arduino_dualpushbutons.ino
// Description: Use pushbuttons for digital input
// Circuit:
//    Connect any pin on pushbutton 1 to ground (GND).
//    Connect the opposite diagonal pin of the pushbutton to
//    digital pin 2.
//
//    Connect any pin on pushbutton 2 to ground (GND).
//    Connect the opposite diagonal pin of the pushbutton to
//    digital pin 3.
//
//    Also connect 10K resistors (brown/black/red) between
//    digital pins 2 and 3 and GND. These are called "pullup"
//    resistors. They ensure that the input pin will be either
//    5V (unpushed) or GND (pushed), and not somewhere in between.
//    (Remember that unlike analog inputs, digital inputs are only
//    HIGH or LOW.)

const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
const int LED_PIN      = 13;

void setup() {
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int btn_1_state, btn_2_state;

  btn_1_state = digitalRead(BUTTON_1_PIN);
  btn_2_state = digitalRead(BUTTON_2_PIN);

  if (((btn_1_state == LOW) || (btn_2_state == LOW)) && !
      ((btn_1_state == LOW) && (btn_2_state == LOW))) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
