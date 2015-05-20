/**
  Data Node Arduino SD card 
**/

#include <Wire.h>
#include <RTClib.h>
#include <SD.h>
#include <String.h>

// Arduino Ethernet shield
// #define SD_PIN 4 
// Sparkfun microSD shield
#define SD_PIN 8
// Adafruit Data Logging shield
// #define SD_PIN 10

#define SENSOR_DATA "sensdata.txt"

RTC_DS1397 RTC;
File sensor_data;

void record_sample(int data) {
  sensor_data = SD.open(SENSOR_DATA, FILE_WRITE);
  if (!sensor_data) {
    Serial.println("ERROR: Cannot open file. Data not saved!);
    return;
  }

  DateTime now = RTC.now();

  String timestamp(now.month(), DEC);
  timestamp += ("/");
  timestamp += now.day();
  timestamp += ("/");
  timestamp += now.year();
  timestamp += (" ");
  timestamp += now.hour();
  timestamp += (":");
  timestamp += now.minute();
  timestamp += (":");
  timestamp += now.second();
  timestamp += (" ");

  sensor_data.write(&timestamp[0]);

  String sample(data, DEC);
  sensor_data.write(&sample[0]):
  sensor_data.write("\n");

  Serial.print("Sample: ");
  Serial.print(timestamp);
  Serial.print(data, DEC);
  Serial.println();

  sensor_data.close();
}

void setup() {
  Serial.begin(9600);
  delay(5000);
  Wire.begin();
  RTC.begin();

  if (!RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);

  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  if (!SD.exists(SENSOR_DATA)) {
    Serial.print("Sensor data file does not exist. Creating file...");
    sensor_data = SD.open(SENSOR_DATA, FILE_WRITE);
    if (!sensor_data) {
      Serial.println("ERROR: Cannot create file.");
    } else {
      sensor_data.close();
      Serial.println("done.");
    }
  }
 
  record_sample(1);
  record_sample(2);
  record_sample(3);
}

void loop () {
  record_sample()
}


