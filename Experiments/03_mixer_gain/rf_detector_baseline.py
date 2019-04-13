#!/usr/bin/env python

import serial
import sys
from DG1022 import *
import usbtmc

ser = serial.Serial('/dev/ttyUSB0', baudrate=19200, bytesize=7,parity='O', stopbits=1, timeout=3)

def ut61e_get_mv(s):
    s.reset_input_buffer()
    line = s.readline()
    line = s.readline()
    #print(line)
    mv = float(line[1:6])/100
    return mv

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

r.SetImpedance(1, 50)
r.SetAmplitude(1, -30)
r.SetFrequency(1, 25000000)
r.SetEnabled(1, True)
    
for dbm in range(-30, 17):
    r.SetAmplitude(1, dbm)
    sleep(2)
    mv = ut61e_get_mv(ser)
    print("%f;%f"%(dbm, mv))
