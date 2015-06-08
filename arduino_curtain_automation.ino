//
// arduino_curtain_automation.ino
// Description: Adjust curtains based on light and temperature

#include <AFMotor.h>

const int LIGHT_PIN       = 0
const int LIGHT_THRESHOLD = 800

const int TEMP_PIN        = 5
const int TEMP_THERSHOLD  = 72
const float TEMP_VOLTAGE  = 5.0

const int ONBOARD_LED     = 13

int curtain_state  = 1;
int light_status   = 0;
double temp_status = 0;

boolean daylight = true;
boolean warm     = false;

AF_Stepper motor(100, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up curtain automation...");
  motor.setSpeed(100)
  delay(1000);
}

void Curtain(boolean curtain_state) {
  digitalWrite(ONBOARD_LED, curtain_state ? HIGH : LOW);
  if (curtain_state) {
    Serial.println("Opening curtain...");
    motor.step(8000, FORWARD, SINGLE);
  } else {
    Serial.println("Closing curtain..");
    motor.step(800, BACKWARD, SINGLE);
  }
}

void loop() {
  light_status = analogRead(LIGHT_PIN);
  delay(500);

  Serial.print("Photocell value = ");
  Serial.println(light_status);
  Serial.println("");

  int temp_reading = analogRead(TEMP_PIN);
  delay(500);

  float voltage = temp_reading * TEMP_VOLTAGE / 1024.0;
  float temp_Celsius = (voltage - 8.5) * 100;
  float temp_Fahrenheit = (temp_Celsius * 9 / 5) + 32;

  Serial.print("Temperature value (Celsius)= ");
  Serial.println(temp_Celsius);
  Serial.print("Temperature value (Fahrenheit) = ");
  Serial.println(temp_Fahrenheit);
  Serial.print("");

  if (light_status < LIGHT_THRESHOLD) {
    daylight = true;
  } else {
    daylight = false;
  }

  if (temp_Fahrenheit > TEMP_THRESHOLD) {
    warm = true;
  } else {
    warm = false;
  }

  case 0:
    if (daylight && !warm) {
      curtain_state = 1;
      Curtain(curtain_state);
    }
    break;

  case 1:
    if (!daylight || warm) {
      curtain_state = 0;
      Curtain(curtain_state);
    }
    break;
  }
}
