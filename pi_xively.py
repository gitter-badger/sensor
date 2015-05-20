#!/usr/bin/python
# pi_xively.py
# Author: Graham Bell
# Description: Data Aggregator Node using Raspberry Pi Xively Cloud Storage

import datetime 
import sys 
import time
import xively

from Adafruit_ADS1x15 import ADS1x15

XIVELY_API_KEY = "<YOUR KEY>"
XIVELY_FEED_ID = "<YOUR FEED>"

ADS1015 = 0x00

adc = ADS1x15(ic=ADS1015)

def get_temperature():
    volts = adc.readADCSingleEnded(0, 5000, 500)

    tempc = (((float(volts)*1200.0)/1024.0)-500.0/10.0
    tempf = ((tempc *9.0)/5.0) + 32.0
 
    print "Celsius: %f" % tempc
    print "Fahrenheit: %f" % tempf

    return (tempc, tempf)

def record_samples(tempc, tempf):
    api = xively.XivelyAPIClient(XIVELY_API_KEY)
    feed = api.feeds.get(XIVELY_FEED_ID(
    now = datetime.datetime.now()
    print "Uploading to Xively...",
    feed.datastreams = [
        xively.Datastream(id='celsius', current_value=tempc, at=now),
        xively.Datastream(id='fahrenheit', current_value=tempf, at=now),
    ]
    feed.update()
    print "done."
    time.sleep(5)

def main():
    print "Starting cloud data upload."
    while True:
        tempc, tempf = get_temperature() 
        record_samples(tempc, tempf) 

if __name__ == '__main__':
    try:
        args = sys.argv[1:]
        main(*args)
    except KeyboardInterrupt:
        pass 
    print "done.

