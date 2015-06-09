//
// arduino_motor.ino
// Description: Use a transistor to spin a motor at different speeds.
// Circuit:
//   Transistor:
//     Connect the black wire on the motor to the COLLECTOR pin on the transistor.
//     Connect the BASE pin through a 330 Ohm resistor to digital pin 9.
//     Connect the EMITTER pin to GND.
//   Motor:
//     You've already connected the black wire on the motor to the
//     COLLECTOR pin on the transistor.
//     Connect the other (red) wire on the motor to 5V.
//   Flyback diode:
//     Connect the side of the diode with the band (cathode) to 5V
//     Connect the other side of the diode (anode) to the black wire on the motor.

// We'll be controlling the motor from pin 9.
// This must be one of the PWM-capable pins.

const int MOTOR_PIN = 9;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // motor_on_and_off();
  // motor_alternate_speed();
  // motor_acceleration();
  serial_speed();
}

// Turn the motor on and off.
void motor_on_and_off() {
  int on_time  = 3000;
  int off_time = 3000;

  digitalWrite(MOTOR_PIN, HIGH);
  delay(on_time);
  digitalWrite(MOTOR_PIN, LOW);
  delay(off_time);
}

// Alternate between two speeds.
void motor_alternate_speed() {
  int speed_1 = 200;
  int time_1  = 3000;

  int speed_2 = 50;
  int time_2  = 3000;

  analogWrite(MOTOR_PIN, speed_1);
  delay(time_1);
  analogWrite(MOTOR_PIN, speed_2);
  delay(time_2);
}

// Slowly accelerates the motor to full speed, then back down to zero.
void motor_acceleration() {
  int speed;
  int pause = 20;

  // accelerate the motor
  for(speed = 0; speed <= 255; speed++) {
    analogWrite(MOTOR_PIN, speed);
    delay(pause);
  }

  // decelerate the motor
  for(speed = 255; speed >= 0; speed--) {
    analogWrite(MOTOR_PIN, speed);
    delay(pause);
  }
}

// Type a speed into the serial monitor
void serial_speed() {
  int speed;

  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();

  while(true) {
    while (Serial.available() > 0) {
      speed = Serial.parseInt();
      speed = constrain(speed, 0, 255);

      Serial.print("Setting speed to ");
      Serial.println(speed);

      analogWrite(MOTOR_PIN, speed);
    }
  }
}
