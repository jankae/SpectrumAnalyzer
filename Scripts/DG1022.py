#!/usr/bin/python

import os
from time import sleep
import  threading
import Queue
import platform

class RigolDG:
    SINE,SQUARE,RAMP,PULSE,NOISE,ARB = range(0,6)
    CH1, CH2 = range(6,8)
    VPP,VRMS,DBM = range(8,11)

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

    def SetImpedance(self, channel, ohms):
        if ohms != 0:
            self.write("OUTP"+str(channel)+":IMP "+str(ohms))
            self.write("SOUR"+str(channel)+":VOLT:UNIT DBM")
        else:
            self.write("OUTP"+str(channel)+":IMP INF")
            self.write("SOUR"+str(channel)+":VOLT:UNIT VPP")

    def SetFrequency(self, channel, freq):
        self.write("SOUR"+str(channel)+":FREQ "+str(freq))

    def SetAmplitude(self, channel, ampl):
        self.write("SOUR"+str(channel)+":VOLT "+str(ampl))

    def SetEnabled(self, channel, enable):
 #       while (self.IsEnabled(channel) != enable):
        msg = "OUTP" + str(channel) + " ";
        if enable:
            msg += "ON";
        else:
            msg += "OFF";
        self.write(msg)

    def IsEnabled(self, channel):
        """ Check if we've got the ouput enabled"""
        ans = self.ask("OUTP" + str(channel) + "?")
        if 'ON' in ans:
            return True
        else:
            return False

 
    def write(self, message=""):
        """ send the message using the low level control"""
        self.dev.write(message)

    def read(self):
        """ read the message using the low level control"""
        return self.dev.read()

    def ask(self, message=""):
        """ request a response using the low level control"""
        self.dev.write(message)
        sleep(0.1)
        return self.dev.read()


    def Disconnect(self):
        """ Call this when you're done using the unit"""
        self.dev.close()

