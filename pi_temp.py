#!/usr/bin/python
# pi_temp.py
# Author: Charles Bell
# Description: Read from a digital temperature sensor

import glob 
import os
import time

os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')

datadir = glob.glob('/sys/bus/w1/devices/28*')[0]
datafile = os.path.join(datadir, 'w1_slave')

def read_data():
    f = open(datafile, 'r')
    lines = f.readlines()
    f.close() 
    return lines

def get_temp():
    temp_c = None
    temp_f = None
    lines = read_data()

    while not lines[0].strip().endswith('YES'):
        time.sleep(0.25)
        lines = read_data()

    pos = lines[1].find('t=')

    if pos != -1:
        temp_string = lines[1][pos+2:]
        temp_c = float(temp_string) / 1000.00
        temp_f = temp_c * 9.00 / 5.00 + 32.00
        return temp_c, temp_f 

while True:
    temp_c, temp_f = get_temp()
    print("Temperature is {0} degrees Celsius, " +
    "{1} degrees Fahrenheit.".format(temp_c, temp_f))
    time.sleep(1)

