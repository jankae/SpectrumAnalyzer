#!/usr/bin/python

import os
from time import sleep
import  threading
import Queue
import platform

class RigolDS:
    """ Class to control the Rigol DS1000 series oscilloscope"""
    def __init__(self,device):
        self.dev = device
        self.Reset()

    def GetName(self):
        self.write("*IDN?")
        sleep(0.01)
        return self.read()

    def Reset(self):
        """ Reset the instrument"""
        self.write("*RST")

    def Stop(self):
        self.write(":STOP")

    def Run(self):
        self.write(":RUN")

    def EnableChannel(self, channel, on):
        if on:
            self.write(":CHAN"+str(channel)+":DISP ON")
        else:
            self.write(":CHAN"+str(channel)+":DISP OFF")

    def ChannelOffset(self, channel, offset):
        self.write(":CHAN"+str(channel)+":OFFS "+str(offset))

    def ChannelScale(self, channel, scale):
        self.write(":CHAN"+str(channel)+":SCAL "+str(scale))

    def TimeScale(self, scale):
        self.write(":TIM:SCAL {0:.10f}".format(scale))

    def GetRMS(self, channel):
        return float(self.dev.ask(":MEAS:VRMS? CHAN"+str(channel)))

    def write(self, message=""):
        """ send the message using the low level control"""
        self.dev.write(message)

    def read(self):
        """ read the message using the low level control"""
        return self.dev.read()

    def Disconnect(self):
        """ Call this when you're done using the unit"""
        self.dev.close()

