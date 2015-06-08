//
// arduino_rgb_led.ino
// Description: Display a rainbow of colors!
// http://learn.sparkfun.com/products/2

const int RED_PIN   = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN  = 11;

int pause = 1000;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  mainColors();
  showSpectrum();
}

void mainColors() {
  // Off (all LEDs off):
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(pause);

  // Red (turn just the red LED on):
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(pause);

  // Green (turn just the green LED on):
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(pause);

  // Blue (turn just the blue LED on):
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(pause);

  // Yellow (turn red and green on):
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(pause);

  // Cyan (turn green and blue on):
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(pause);

  // Purple (turn red and blue on):
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(pause);

  // White (turn all the LEDs on):
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(pause);
}

void showSpectrum() {
  int x;

  for (x = 0; x < 768; x++) {
    showRGB(x);
    delay(10);
  }
}

void showRGB(int color) {
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  if (color <= 255) {
    redIntensity = 255 - color;
    greenIntensity = color;
    blueIntensity = 0;
  } else if (color <= 511) {
    redIntensity = 0;
    greenIntensity = 255 - (color - 256);
    blueIntensity = (color - 256);
  } else {
    redIntensity = (color - 512);
    greenIntensity = 0;
    blueIntensity = 255 - (color - 512);
  }

  analogWrite(RED_PIN, redIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
  analogWrite(GREEN_PIN, greenIntensity);
}
