/**
  Arduino 3-Axis Gyroscope ITG-3200
**/

#include <Wire.h>

const int itgAddress = 0x69;

const byte SMPLRT_DIV = 0x15;
const byte DLPF_FS = 0x16;
const byte INT_CFG = 0x17;
const byte PWR_MGM = 0x3E;
const byte GYRO_X_ADDRESS = 0x1D;
const byte GYRO_Y_ADDRESS = 0x1F;
const byte GYRO_Z_ADDRESS = 0x21;

const byte DLPF_CFG_0 = 0x1;
const byte DLPF_CFG_1 = 0x2;
const byte DLPF_CFG_2 = 0x4;
const byte DLPF_FS_SEL_0 = 0x8;
const byte DLPF_FS_SEL_1 = 0x10;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  itgWrite(DLPF_FS, (DLPF_FS_SEL_0|DLPF_FS_SEL_1|DLPF_CFG_0));
  itgWrite(SMPLRT_DIV, 9);
}

void loop() {
  int xRate, yRate, zRate;
  
  xRate = readAxis(GYRO_X_ADDRESS);
  yRate = readAxis(GYRO_Y_ADDRESS);
  zRate = readAxis(GYRO_Z_ADDRESS);

  int temperature = 22;
  Serial.print(temperature);
  Serial.print(',');
  Serial.print(xRate);
  Serial.print(',');
  Serial.print(yRate);
  Serial.print(',');
  Serial.print(zRate);

  delay(10);
}

void itgWrite(char registerAddress, char data) {
  Wire.beginTransmission(itgAddress);
  Wire.write(registerAddress);
  Wire.write(data);
  Wire.endTransmission();
}

unsigned char itgRead(char registerAddress) {
  unsigned char data = 0;

  Wire.beginTransmission(itgAddress);
  Wire.write(registerAddress);
  Wire.endTransmission);

  Wire.beginTransmission(itgAddress);
  Wire.requestFrom(itgAddress, 1);

  if (Wire.available()) {
    data = Wire.read();
  }

  Wire.endTransmission();
  return data;
}

int readAxis(byte axisRegAddress) {
  int data = 0;
  data = itgRead(axisRegAddress) << 8;
  data |= itgRead(axisRegAddress + 1);
  return data;
}
