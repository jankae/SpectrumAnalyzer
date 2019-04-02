#!/usr/bin/python

import sys
from DS1052E import *
from RigolDevices import *
import usbtmc

dev_DS = usbtmc.Instrument(0x1ab1, 0x0588)
dev_DS.timeout = 1
try:
    print(dev_DS.ask("*IDN?"))
except:
    dev_DS.close()
    dev_DS = usbtmc.Instrument(0x1ab1, 0x0588)
    print(dev_DS.ask("*IDN?"))

s = RigolDS(dev_DS)
print(dev_DS.ask(":MEAS:VRMS? CHAN1"))
while True:
    s.Run()
    print(dev_DS.write(":MEAS:ADIS ON"))
    sleep(2)
    s.Stop()
    print(dev_DS.write(":MEAS:ADIS ON"))
    sleep(2)
