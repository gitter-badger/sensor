//
// arduino_ps2mouse.ino
// Description: Arduino PS2 Mouse Sensor Node

#define WProgram.h Arduino.h
#include <ps2.h>

const int DATA_PIN    = 5;
const int CLOCK_PIN   = 6;
const int X_LED_PIN   = 9;
const int Y_LED_PIN   = 11;
const int MOUSE_RANGE = 255;

const byte REQUEST_DATA = 0xeb;

char x;
char y;
byte status;

int xPosition   = 0;
int yPosition   = 0;
int xBrightness = 0;
int yBrightness = 0;

PS2 mouse(CLOCK_PIN, DATA_PIN);

void setup() {
  mouseBegin();
}

void loop() {
  mouse.write(REQUEST_DATA);
  mouse.read();
  status = mouse.read();
  if (status & 1) {
    xPosition = 0;
  }
  if (status & 2) {
    yPosition = 0;
  }

  x = mouse.read();
  y = mouse.read();
  if (x!= 0 || y != 0) {
    xPosition = xPosition + x;
    xPosition = constrain(xPosition, -MOUSE_RANGE, MOUSE_RANGE);

    xBrightness = map(xPosition, -MOUSE_RANGE, MOUSE_RANGE, 0, 255);
    analogWrite(X_LED_PIN, xBrightness);

    yPosition = constrain(yPosition + y, -MOUSE_RANGE, MOUSE_RANGE);
    yBrightness = map(yPosition, -MOUSE_RANGE, MOUSE_RANGE, 0, 255);
    analogWrite(yLedPen, yBrightness);
  }
}

void mouseBegin() {
  mouse.write(0xff);
  delayMicroseconds(100);
  mouse.read();
  mouse.read();
  mouse.read();
  mouse.write(0xf0);
  mouse.read();
  delayMicroseconds(100);
}
