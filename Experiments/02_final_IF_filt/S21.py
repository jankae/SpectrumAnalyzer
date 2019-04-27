#!/usr/bin/python

import sys
from DS1052E import *
from DG1022 import *
import usbtmc
import math
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) != 5:
    print "Usage: S21.py center_freq span points reference"
    exit()

dev_DG = usbtmc.Instrument(0x1ab1, 0x0642)
dev_DG.timeout = 0.1
try:
    print(dev_DG.ask("*IDN?"))
except:
    dev_DG.close()
    dev_DG = usbtmc.Instrument(0x1ab1, 0x0642)
    dev_DG.timeout = 0.1
    print(dev_DG.ask("*IDN?"))

dev_DS = usbtmc.Instrument(0x1ab1, 0x0588)
dev_DS.timeout = 0.1
try:
    print(dev_DS.ask("*IDN?"))
except:
    dev_DS.close()
    dev_DS = usbtmc.Instrument(0x1ab1, 0x0588)
    print(dev_DS.ask("*IDN?"))

s = RigolDS(dev_DS)
g = RigolDG(dev_DG)

reference = float(sys.argv[4])

g.SetImpedance(1, 50)
g.SetAmplitude(1, reference)

s.EnableChannel(2, False)

scale = 0.3
s.ChannelScale(1, scale)
# scope needs delay here?
sleep(0.3)
s.ChannelOffset(1, 0)
sleep(0.3)
g.SetEnabled(1, True)

CenterFreq = float(sys.argv[1])
Span = float(sys.argv[2])
Steps = int(sys.argv[3])

StartFreq = int(CenterFreq-Span/2)
StopFreq = int(CenterFreq+Span/2)
FreqStep =    int(Span/Steps)
s.TimeScale(1.0/StartFreq)
sleep(3)

points_dbm = [None] * Steps 
points_freq = [None] * Steps 

plt.ion()

while True:
    for i in range(0, Steps):
        freq = StartFreq + FreqStep * i
        g.SetFrequency(1, freq)
        s.TimeScale(1.0/freq)
        sleep(0.4)
        rms = s.GetRMS(1)
        while rms < scale * 4 / (math.sqrt(2)*3) and scale > 0.001:
            scale = scale / 2
            #print("Decreased to " + str(scale))
            s.ChannelScale(1, scale)
            sleep(0.6)
            rms = s.GetRMS(1)
        while rms > scale * 4 / math.sqrt(2):
            scale = scale * 2
            #print("Increased to " + str(scale))
            s.ChannelScale(1, scale)
            sleep(0.6)
            rms = s.GetRMS(1)
        dbm = 10 * math.log10(rms*rms/50) + 30
        print("{};{}".format(freq, dbm - reference))
        points_freq[i] = freq
        points_dbm[i] = dbm - reference
        plt.clf()
        plt.plot(points_freq, points_dbm)
        plt.pause(0.05)
    
g.SetEnabled(1, False)

