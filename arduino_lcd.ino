//
// arduino_lcd.ino
// Description: display text or numeric data.
// http://arduino.cc/en/Reference/LiquidCrystal
// Circuit:
//   1 to GND
//   2 to 5V
//   3 to the center pin on the potentiometer
//   4 to Arduino digital pin 12
//   5 to GND
//   6 to Arduino digital pin 11
//   7 (no connection)
//   8 (no connection)
//   9 (no connection)
//   10 (no connection)
//   11 to Arduino digital pin 5
//   12 to Arduino digital pin 4
//   13 to Arduino digital pin 3
//   14 to Arduino digital pin 2
//   15 to 5V
//   16 to GND

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  // lcd.setCursor(0,1);       // Set the cursor to the position
  // lcd.print("       ");     // Erase the largest possible number
  // lcd.setCursor(0,1);       // Reset the cursor to the original position
  // lcd.print(millis()/1000); // Print our value
}
