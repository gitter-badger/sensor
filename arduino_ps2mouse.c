/**
  Arduino PS2 Mouse Sensor Node
**/

#define WProgram.h Arduino.h
#include <ps2.h>

const int dataPin = 5;
const int clockPin = 6;

const int xLedPin = 9;
const int yLedPin = 11;

const int mouseRange = 255;

char x;
char y;
byte status;

int xPosition = 0;
int yPosition = 0;
int xBrightness = 0;
int yBrightness = 0;

const byte REQUEST_DATA = 0xeb;

PS2 mouse(clockPin, dataPin);

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
    xPosition = constrain(xPosition, -mouseRange, mouseRange);
    
    xBrightness = map(xPosition, -mouseRange, mouseRange, 0, 255);
    analogWrite(xLedPin, xBrightness);
 
    yPosition = constrain(yPosition + y, -mouseRange, mouseRange);
    yBrightness = map(yPosition, -mouseRange, mouseRange, 0, 255);
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
