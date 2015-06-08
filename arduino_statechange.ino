//
// arduino_statechange.ino
// Description: Detect state change for digital input,

const int BUTTON_PIN = 2;
const int LED_PIN    = 13;

int push_counter         = 0;
int current_button_state = 0;
int prev_button_state    = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  current_button_state = digitalRead(BUTTON_PIN);

  if (button_state != prev_button_state) {
    if (button_state == HIGH) {
      push_counter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(push_counter);
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  prev_button_state = current_button_state;

  // Turn on the LED every four button pushes
  if (push_counter % 4 == 0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
