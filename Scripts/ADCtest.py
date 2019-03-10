#!/usr/bin/python

import sys
from DG1022 import *

r = RigolDG('/dev/usbtmc1')

# Channel 2 is the reference clock for the whole system
# 25MHz 0dbm
r.SetImpedance(2, 50)
r.SetFrequency(2, 25000000)
r.SetAmplitude(2, 0)

r.SetEnabled(2, True)

# Channel 1 is swept through a range of frequencies, testing the ADC FFT response
StartFreq = 10000000
StopFreq = 18000000
FreqStep = 100000

r.SetImpedance(1, 50)
r.SetAmplitude(1, -20)
r.SetFrequency(1, StartFreq)
r.SetEnabled(1, True)
for freq in range(StartFreq, StopFreq, FreqStep):
    r.SetFrequency(1, freq)
    sleep(0.1)

r.SetEnabled(1, False)
r.SetEnabled(2, False)
#r.Disconnect()
