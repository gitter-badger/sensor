#!/usr/bin/python
# pi_bpm085.py
# Author: Charles Bell
# Description: Reads barometric pressure and altitude from an I2C sensor

import time

from Adafruit_BMP085 import BMP085

bmp085 = BMP085(0x77)

while True:
    try:
        pressure = float(bmp085.readPressure()) / 100
        altitude = bmp085.readAltitude()
    
        print("The barometric pressure at altitude {0:.2f}"
       "is  {1:.2f} hPa.".format(pressure, altitude)) 

        time.sleep(3)

    except KeyboardInterrupt:
        break

