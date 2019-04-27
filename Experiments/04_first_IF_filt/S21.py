#!/usr/bin/python

import sys
import math
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import serial

if len(sys.argv) != 2:
    print "Usage: ADCtest.py port"
    exit()

ser = serial.Serial(port=sys.argv[1], baudrate=115200)

Steps = 1000

points_dbm = [None] * Steps 
points_freq = [None] * Steps 

plt.ion()

cnt = 0
step = 0
last_freq = 0

while True:
    line = ser.readline()
    split = line.split()
    if(len(split) != 7):
        continue
    dbm = float(split[6])
    freq = int(split[4][:-1])
    print "{};{}".format(freq, dbm)
    if freq < last_freq:
        step = 0
    last_freq = freq        
    points_dbm[step] = dbm
    points_freq[step] = freq
    step = step + 1
    cnt = cnt + 1
    if cnt >= 10:  
        plt.clf()
        plt.plot(points_freq, points_dbm)
        plt.xlabel('frequency')
        plt.ylabel('dbm')
        plt.pause(0.005)
        cnt = 0
