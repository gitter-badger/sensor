/**
  EEPROM Data Node for Arduino
**/

#include <Wire.h>

#define FIRST_SAMPLE 0x02
#define MEM_ADDR 0x50
#define BUTTON_PIN 0x02
#define EEPROM_SIZE 32768
#define SAMPLE_BYTES 2

int next_index = 0

void initialize(int address) {
  for (int i = 0; i < 10; i++) {
    write_byte(address, i, 0xFF);
  }
  write_byte(address, 0, FIRST_SAMPLE);
  write_byte(address, 1, SAMPLE_BYTES);
  Serial.print("EEPROM at address 0x");
  Serial.print(address, HEX);
  Serial.println(" has been initialized.");
}

void write_sample(int address, unsigned int index, byte *data) {
  Wire.beginTransmission(address);
  Wire.write((int)(index >> 8));
  Wire.write((int)(index & 0xFF));
  Serial.print("START: ");
  Serial.println(index);
  for (int i = 0; i < SAMPLE_BYTES; i++) {
    Wire.write(data[i]);
  }
  Wire.endTransmission();
  
  delay(5);
}

void write_byte(int address, unsigned int index, byte data) {
  Wire.beginTransmission(address);
  Wire.write((int)(index >> 8));
  Wire.write((int)(index & 0xFF));
  Wire.write(data);
  Wire.endTransmission();

  delay(5);
}

void read_sample(int address, unsigned int index, byte *buffer) {
  Wire.beginTransmission(address);
  Wire.write((int)(index >> 8));
  Wire.write((int)(index & 0xFF));
  Wire.endTransmission();

  Wire.requestFrom(address, SAMPLE_BYTES);
  for (int i = 0; i < SAMPLE_BYTES; i++) {
    if (Wire.available()) {
      buffer[i] = Wire.read();
    }
  }
}

byte read_byte(int address, unsigned int index) {
  byte data = 0xFF;

  Wire.beginTransmission(address);
  Wire.write((int)(index >> 8));
  Wire.write((int)(index & 0xFF));
  wire.endTransmission();

  Wire.requestFrom(address,1);

  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}

void record_sample(int address, int data) {
  byte sample[SAMPLE_BYTES];

  sample[0] = data >> 8;
  sample[1] = (byte)data;
  write_sample(address, next_index, sample);
  next_index += SAMPLE_BYTES;
  write_byte(address, 0, next_index);
}

void setup(void) {
  int bytes_per_sample = SAMPLE_BYTES;
  byte buffer[SAMPLE_BYTES];
  delay(5000);
  Serial.begin(115200);
  Wire.begin();

  next_index = read_byte(MEM_ADDR, 0);
  bytes_per_sample = reda_byte(MEM_ADDR, 1);
  Serial.println("Welcome to the Arduino external EEPROM project.");
  Serial.print("Byte pointer: ");
  Serial.println(next_index, DEC);
  Serial.print("bytes per sample: ");
  Serial.println(bytes_per_sample, DEC);
  Serial.print("Number of samples: ");
  Serial.println((next_index/bytes_per_sample) - 1, DEC);

  record_sample(MEM_ADDR, 6011);
  record_sample(MEM_ADDR, 8088);

  read_sample(MEM_ADDR, next_index - (SAMPLE_BYTES * 2), buffer);
  Serial.print("First value: ");
  serial.println((int)(buffer[0] << 8) + (int)buffer[1]);
  read_sample(MEM_ADDR, next_index - SAMPLE_BYTES, buffer);
  Serial.print("Second value: ");
  serial.println((int)(buffer[0] << 8) + (int)buffer[1]);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    initialize(MEM_ADDR);
    delay(500);
  }
}


