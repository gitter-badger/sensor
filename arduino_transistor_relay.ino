//
// arduino_transistor_relay.ino
// Description: Use a transistor to drive a relay
// Circuit:
//   Transistor:
//     Connect the BASE pin through a 1K resistor to digital pin 2.
//     Connect the EMITTER pin to GND.
//
//   Relay coil:
//     Connect one side of the coil to the COLLECTOR pin on the transistor.
//     Connect other side of the coil to 5V.
//
//   Diode:
//     Connect the side of the diode with the band (cathode) to 5V
//     Connect the other side of the diode (anode) to the COLLECTOR
//     pin of the transistor.
//
//   Relay contacts and LEDs:
//     Connect the COMMON side of the switch to a 330 Ohm resistor.
//     Connect the other side of the above resistor to 5V.
//     Connect the NC (Normally Closed) side of the switch to the positive (longer) leg of LED 1.
//     Connect the NO (Normally Open) side of the switch to the positive (longer) leg of LED 2.
//     Connect the negative sides (shorter leg) of both LEDs to GND.

const int RELAY_PIN = 2;
const int PAUSE     = 1000;

// WARNING: relays are mechanical devices that wear out quickly

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(PAUSE);
  digitalWrite(RELAY_PIN, LOW);
  delay(PAUSE);
}
