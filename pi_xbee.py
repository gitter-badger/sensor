#!/usr/bin/python
# pi_xbee.py
# Author: Graham Bell
# Description: Data Aggregator Node using XBee 

#import pprint
import serial
import xbee 

SERIAL_PORT = '/dev/ttyAMA0'
BAUD_RATE = 9600

ser_port = serial.Serial(SERIAL_PORT, BAUD_RATE)

xbee1 = xbee.zigbee.ZigBee(ser_port)

while True:
    try: 
        data_samples = xbee1.wait_read_frame()
        address = data_samples['source_addr_long']
        print("Reading from XBee:")
        samples = data_samples['samples'][0]

        temp_c = ((samples['adc-3] * 1200.0 / 1024.0) - 500.0) / 10.0
        temp_f = ((temp_c * 9.0) / 5.0) + 32.0

        print("Temperature is {0} c, "
        "{1} f".format(temp_c, temp_f)) 

        volts = (float(samples['adc-7']) * (1200.0 / 1024.0)) / 1000.0
        print("Supply voltage = {0} volts.".format(volts))

    except KeyboardInterrupt:
        break

ser_port.close()

