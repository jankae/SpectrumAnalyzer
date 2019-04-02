#!/usr/bin/python

import sys
from DG1022 import *
from RigolDevices import *
import usbtmc
import serial


if len(sys.argv) != 2:
    print "Usage: ADCtest.py port"
    exit()

ser = serial.Serial(port=sys.argv[1], baudrate=115200)

dev_DG = usbtmc.Instrument(0x1ab1, 0x0642)
dev_DG.timeout = 0.1
try:
    print(dev_DG.ask("*IDN?"))
except:
    dev_DG.close()
    dev_DG = usbtmc.Instrument(0x1ab1, 0x0642)
    dev_DG.timeout = 0.1
    print(dev_DG.ask("*IDN?"))

r = RigolDG(dev_DG)

# Channel 2 is the reference clock for the whole system
# 25MHz 0dbm
r.SetImpedance(2, 50)
r.SetFrequency(2, 25000000)
r.SetAmplitude(2, 10)

r.SetEnabled(2, True)

# Channel 1 is swept through a range of frequencies, testing the ADC FFT response
CenterFreq = 18750000
Span = 20000
Steps = 500

StartFreq = CenterFreq-Span/2
StopFreq = CenterFreq+Span/2
FreqStep =    Span/Steps 


r.SetImpedance(1, 50)
r.SetAmplitude(1, 0)
r.SetFrequency(1, StartFreq)
r.SetEnabled(1, True)
# clear any previous messages
for i in range(0, 20):
    line = ser.readline()
for freq in range(StartFreq, StopFreq, FreqStep):
    r.SetFrequency(1, freq)
    sleep(0.1)
    ser.reset_input_buffer()
    line = ser.readline()
    num = 0
    avg = 4
    for x in range(0, avg):
        line = ser.readline()
        split = line.split()
        if(len(split) != 6):
            print split
        num = num + float(split[5])
    num = num / avg
    print "{};{}".format(freq, num)

r.SetEnabled(1, False)
r.SetEnabled(2, False)
#r.Disconnect()
