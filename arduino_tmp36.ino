//
// arduino_tmp36.ino
// Description: Use TMP36 to read temperature
// Circuit:
//   Connect the 5V pin to 5 Volts (5V).
//   Connect the SIGNAL pin to ANALOG pin 0.
//   Connect the GND pin to ground (GND).

const int TEMP_PIN = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage, degreesC, degreesF;

  voltage  = getVoltage(TEMP_PIN);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  delay(1000);
}

// Converts analogRead() into a 0.0 to 5.0 voltage
float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}

// Other things to try:
//   Turn on an LED if the temperature is above or below a value.
//   Read that threshold value from a potentiometer, ah ha thermostat!
