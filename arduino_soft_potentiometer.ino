//
// arduino_soft_potentiometer.ino
// Description: Use the soft potentiometer to change RGB LED color
// Circuit:
//   Soft potentiometer:
//     Connect the middle pin to ANALOG IN pin 0 on the Arduino.
//     Connect one side to 5V.
//     Connect the other side to GND.
//     Also connect a 10K resistor from the middle pin to GND.
//
//     HINT: the soft pot will only work while you're actively
//     pressing on it; at other times it will "float" to random
//     values. To prevent this, we've added a 10K pull-down resistor
//     to the middle pin (output voltage). This will keep the output
//     at zero volts when the pot is not being pressed.
//   RGB LED:
//     Connect RED to a 330 Ohm resistor.
//     Connect the other end of the resistor to Arduino digital pin 9.
//
//     Connect COMMON to GND.
//
//     Connect GREEN through a 330 Ohm resistor.
//     Connect the other end of the resistor to Arduino digital pin 10.
//
//     Connect BLUE through a 330 Ohm resistor.
//     Connect the other end of the resistor to Arduino digital pin 11.

const int SOFT_POT_PIN  = 0;
const int RED_LED_PIN   = 9;
const int GREEN_LED_PIN = 10;
const int BLUE_LED_PIN  = 11;

int red_value, green_value, blue_value;

void setup() {
  analogWrite(SOFT_POT_PIN, OUTPUT)
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(SOFT_POT_PIN);

  setRGB(sensorValue);
}

void setRGB(int RGBposition) {
  int map_rgb1, map_rgb2, constrained1, constrained2;

  // For each channel (red green blue), we're creating a "peak"
  // a third of the way along the 0-1023 range. By overlapping
  // these peaks with each other, the colors are mixed together.
  // http://sfecdn.s3.amazonaws.com/education/SIK/SchematicImages/Misc/RGB_function.jpg

  // Create the red peak, which is centered at 0.
  map_rgb1     = map(RGBposition, 0, 341, 255, 0);
  constrained1 = constrain(map_rgb1, 0, 255);
  map_rgb2     = map(RGBposition, 682, 1023, 0, 255);
  constrained2 = constrain(map_rgb2, 0, 255);
  red_value    = constrained1 + constrained2;

  // Create the green peak, which is centered at 341
  green_value = constrain(map(RGBposition, 0, 341, 0, 255), 0, 255)
             - constrain(map(RGBposition, 341, 682, 0,255), 0, 255);

  // Create the blue peak, which is centered at 682
  blue_value = constrain(map(RGBposition, 341, 682, 0, 255), 0, 255)
            - constrain(map(RGBposition, 682, 1023, 0, 255), 0, 255);

  analogWrite(RED_LED_PIN, red_value);
  analogWrite(GREEN_LED_PIN, green_value);
  analogWrite(BLUE_LED_PIN, blue_value);
}
