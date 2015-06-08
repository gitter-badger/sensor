//
// arduino_photoresistor_led.ino
// Description: Use a photoresistor to control the brightness of an LED
// Circuit:
//    Photo resistor:
//    Connect one side of the photoresistor to 5 Volts (5V).
//    Connect the other side of the photoresistor to ANALOG pin 0.
//    Connect a 10K resistor between ANALOG pin 0 and GND.
//
//    This creates a voltage divider, with the photoresistor one
//    of the two resistors. The output of the voltage divider
//    (connected to A0) will vary with the light level.
//
//    LED:
//    Connect the positive side (long leg) of the LED to
//    digital pin 9. (To vary the brightness, this pin must
//    support PWM, which is indicated by "~" or "PWM" on the
//    Arduino itself.)
//    Connect the negative side of the LED (short leg) to a
//    330 Ohm resistor.
//    Connect the other side of the resistor to GND.

const int LDR_PIN = 0;
const int LED_PIN = 9;

int light_level, high = 0, low = 1023;


void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  light_level = analogRead(LDR_PIN);
  // manual_tune();
  auto_tune();

  analogWrite(LED_PIN, light_level);
}

void manual_tune() {
  light_level = map(light_level, 0, 1023, 0, 255);
  light_level = constrain(light_level, 0, 255);
}

void auto_tune() {
  if (light_level < low) {
    low = light_level;
  }

  if (light_level > high) {
    high = light_level;
  }

  light_level = map(light_level, low+30, high-30, 0, 255);
  light_level = constrain(light_level, 0, 255);
}
