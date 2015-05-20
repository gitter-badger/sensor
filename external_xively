/** 
  Data Aggregator Node with Arduino Xively Cloud Storage
**/

#include <SPI.h>
#include <Ethernet.h>
#include <HttpClient.h>
#include <Xively.h>

byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

char xivelyKey[] = "<YOUR_KEY>";

#define FEED_NUMBER <YOUR_FEED>"

#define SENSOR_PIN 0

char sensor1_name[] = "celsius";
char sensor2_name[] = "fahrenheit";
XivelyDatastream datastreams[] = {
  XivelyDatastream(sensor1_name, strlen(sensor1_name), DATASTREAM_FLOAT),
  XivelyDatastream(sensor2_name, strlen(sensor2_name), DATASTREAM_FLOAT),
};

XivelyFeed feed(FEED_NUMBER, datastreams, 2);

EthernetClient client;
XivelyClient xivelyclient(client);

void get_temperature(float *tempc, float *tempf) {
  int adc_data = analogread(SENSOR_PIN);
  
  Serial.printt("Temperature is ");
  *tempc = ((adc_data * 1200.0 / 1024.0) - 500.0) / 10.0;
  Serial.print(*tempc);
  Serial.print("c, ");
  *tempf = ((*tempc * 9.0)/5.0) + 32.0;
  Serial.print(*tempf);
  Serial.print("f");

  delay(1000);
}

void record_sample(float tempc, float tempf) {
  datastreams[0].setFloat(tempc);
  datastreams[1].setFloat(tempf);

  Serial.print("Uploading to Xively... ");
  int ret = xivelyclient.put(feed, xivelyKey);
  Serial.print("done. Return code = ");
  Serial.print(ret);

  delay(15000);
}

void setup() {
  Serial.begin(9600);
  delay(5000);

  Serial.println("Starting cloud data upload.");

  while (!Ethernet.begin(mac_addr)) {
    Serial.println("Error starting Ethernet, trying again");
    delay(1000);
  }
}

void loop() {
  float temp_celsius;
  float temp_fahrenheit;

  get_temperature(&temp_celsius, &temp_fahrenheit);
  record_sample(temp_celsius, temp_fahrenheit);
}

