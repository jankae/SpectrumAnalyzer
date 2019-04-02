import usb.core
import usb.util
import struct
import time
import os
import re
import sys

def find_device(idVendor=None, idProduct=None, iSerial=None):
    "Find USBTMC instrument"

    for dev in usb.core.find(find_all=True):
        # match VID and PID
        found = dev.idVendor == idVendor and dev.idProduct == idProduct

        if not found:
            continue

        if iSerial is None:
            return dev
        else:
            s = ''

            # try reading serial number
            try:
                s = dev.serial_number
            except:
                pass

            if iSerial == s:
                return dev

    return None
