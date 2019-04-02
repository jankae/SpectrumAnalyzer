#!/usr/bin/python

import sys
from DS1052E import *
from DG1022 import *
from RigolDevices import *
import usbtmc
import math

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

reference = 10

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

StartFreq = 1000000
StopFreq = 25000000
FreqStep = 1000000
s.TimeScale(1.0/StartFreq)
sleep(3)

for freq in range(StartFreq, StopFreq + 1, FreqStep):
    g.SetFrequency(1, freq)
    s.TimeScale(1.0/freq)
    sleep(0.4)
    rms = s.GetRMS(1)
    while rms < scale * 4 / (math.sqrt(2)*3) and scale > 0.001:
        scale = scale / 2
        print("Decreased to " + str(scale))
        s.ChannelScale(1, scale)
        sleep(0.4)
        rms = s.GetRMS(1)
    while rms > scale * 4 / math.sqrt(2):
        scale = scale * 2
        print("Increased to " + str(scale))
        s.ChannelScale(1, scale)
        sleep(0.4)
        rms = s.GetRMS(1)
    dbm = 10 * math.log10(rms*rms/50) + 30
    print("{};{}".format(freq, dbm - reference))
    
g.SetEnabled(1, False)

