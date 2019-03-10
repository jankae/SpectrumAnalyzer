#!/usr/bin/python

import os
from time import sleep
import  threading
import Queue
import platform

class usbtmc:
    """ Simple implementation of USBTMC device driver """
    def __init__(self,device):
        self.device = device
        try:
            self.FILE = os.open(device, os.O_RDWR)
        except Exception:
            QMessageBox.about(None,'ERROR','Unable to find requried device\n' +device)
            exit()

    def ask(self, message=""):
        """ Send a query to the unit and read the response."""
        self.write(message)
        return self.read()


    def write(self,command):
        """Send an arbitrary command directly to the device"""
        os.write(self.FILE,command)
       # sleep(0.2)

    def read(self, length = 4000):
        """ Read an arbitary amount of data directly from the device"""
        return os.read(self.FILE, length)

    def getName(self):
        """ Return the unique identifier based on the *IDN? query"""
        seljf.write("*IDN?")
        sleep(0.10)
        return self.read(300)

    def sendReset(self):
        self.write("*RST")

    def close(self):
        """ Returns the ability for the user to press buttons"""
        self.write("SYST:LOC")



class RigolDG:
    SINE,SQUARE,RAMP,PULSE,NOISE,ARB = range(0,6)
    CH1, CH2 = range(6,8)
    VPP,VRMS,DBM = range(8,11)

    """ Class to control the Rigol DS1000 series oscilloscope"""
    def __init__(self,device):
        self.meas = usbtmc(device)
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
        self.meas.write(message)

    def read(self):
        """ read the message using the low level control"""
        return self.meas.read()

    def ask(self, message=""):
        """ request a response using the low level control"""
        self.write(message)
        sleep(0.1)
        return self.read()


    def Disconnect(self):
        """ Call this when you're done using the unit"""
        self.meas.close()

