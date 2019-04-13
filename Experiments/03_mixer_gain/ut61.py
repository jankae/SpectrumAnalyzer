from threading import Thread
class Ut61(object):
    # http://www.noteblok.net/wp-content/uploads/sites/3/2009/11/UT61E.txt
    # 012345678901
    # 020929?000:0
    # Byte 6 -> Schalterstellung
    # 0 - A, 1 - Diode, 2 - Hz, 3 - Ohm, 5 - Durchgang, 6 - F, ; - V / mV, = - uA, ? - mA
    # Byte 7 - Info (Neg, %, Low, OVL): 4 - Neg
    # Byte 10 - AC / DC / Auto
    # Byte 11 - Hold
    # Byte 0 Bereich
    # Byte 1-5 Wert
    # 0
    # Usb hid code from https://github.com/pklaus/ut61e_python


    lastvalue = ""
    usbThread = None
    currentReading = dict()
    convertValues = False

    def __init__(self, convertValues=False):
        self.convertValues = convertValues
        # covertValues = True -> mV bzw. mA werden zu V und A umgerechnet
        self.usbThread = Thread(target=self.readFromUsb, args=())
        self.usbThread.daemon = True
        self.usbThread.start()

    def __insertDecimal(self, stringNumber,decimalPosition,neg="0"):
        if neg == "4":
            return "-" + stringNumber[:decimalPosition] + "." + stringNumber[decimalPosition:]
        else:
            return stringNumber[:decimalPosition] + "." + stringNumber[decimalPosition:]

    def parseValue(self, value):
        #print value
        # TODO bisher nur A / ma, V. Alle anderen Schalterstellungen noch nicht implementiert
        returndict=dict(value=None, unit=None)
        # Extract numerical value
        stringNumber = value[1:6]

        # Get Measurement Type:
        if value[6] == "0":
            returndict["unit"] = "A"
            returndict["value"] = float(self.__insertDecimal(stringNumber,2,value[7]))
        elif value[6] == ";":
            returndict["unit"] = "V"
            if value[0] == "0":
                returndict["value"] = float(self.__insertDecimal(stringNumber,1,value[7]))
            elif value[0] == "1":
                returndict["value"] = float(self.__insertDecimal(stringNumber,2,value[7]))
            elif value[0] == "2":
                returndict["value"] = float(self.__insertDecimal(stringNumber,3,value[7]))
            elif value[0] == "3":
                returndict["value"] = float(self.__insertDecimal(stringNumber,4,value[7]))
            elif value[0] == "4":
                returndict["unit"] = "mV"
                returndict["value"] = float(self.__insertDecimal(stringNumber,3,value[7]))
                if self.convertValues:
                    returndict["unit"] = "V"
                    returndict["value"] = returndict["value"]/1000.0
            else:
                print "Range error"
        elif value[6] == "?":
            returndict["unit"] = "mA"
            if value[0] == "0":
                returndict["value"] = float(self.__insertDecimal(stringNumber,2,value[7]))
            elif value[0] == "1":
                returndict["value"] = float(self.__insertDecimal(stringNumber,3,value[7]))
            if self.convertValues:
                returndict["unit"] = "A"
                returndict["value"] = returndict["value"]/1000.0
        else:
            print "currently not supported"
        #print returndict
        self.currentReading = returndict
        return returndict

    def readFromUsb(self):
        import argparse,sys
        from inspect import cleandoc
        BPS = 19200

        try:
            try:
                import hidraw as hid
            except ImportError:
                import hid
        except ImportError:
            parser.error("You need to install cython-hidapi first!")
        import logging
        loglevel = logging.ERROR
        logging.basicConfig(format='%(message)s', level=loglevel)

        #try:
        if True:
            logging.info("Enumerating Devices")
            devices = hid.enumerate(0, 0)
            print(devices)
            if len(devices) == 0:
                raise NameError('No device found. Check your USB connection.')
            logging.info("Found {} devices: ".format(len(devices)))
            for dev in devices:
                name = dev['manufacturer_string'] + " " + dev['product_string']
                path = dev['path'].decode('ascii')
                logging.info("* {} [{}]".format(name, path))

            logging.info("Opening device")
            h = hid.device()
            try:
                h.open(0x1a86, 0xe008)
            except IOError as ex:
                raise NameError('Cannot open the device. Please check permissions.')

            buf = [0]*6
            buf[0] = 0x0 # report ID
            buf[1] = BPS & 0xFF
            buf[2] = ( BPS >>  8 ) & 0xFF
            buf[3] = ( BPS >> 16 ) & 0xFF
            buf[4] = ( BPS >> 24 ) & 0xFF
            buf[5] = 0x03 # 3 = enable?

            fr = h.send_feature_report(buf)
            if fr == -1:
                raise NameError("Sending Feature Report Failed")
            logging.debug("Feature Report Sent")

            try:
                logging.debug("Start Reading Messages")
                while True:
                    #answer = h.read(256)
                    answer = h.read(256, timeout_ms=1000)
                    if len(answer) < 1: continue
                    nbytes = answer[0] & 0x7
                    if nbytes > 0:
                        if len(answer) < nbytes+1:
                            raise NameError("More bytes announced then sent")
                        payload = answer[1:nbytes+1]
                        data = [b & ( ~(1<<7) ) for b in payload]
                        data = [chr(b) for b in data]
                        data = ''.join(data)
                        if not data.endswith("\r\n"):
                            self.lastvalue = data
                        else:
                            self.lastvalue = self.lastvalue + data
                            self.parseValue(self.lastvalue)
                        #sys.stdout.write(data)
                        #sys.stdout.flush()
            except KeyboardInterrupt:
                logging.info("You pressed CTRL-C, stopping...")

            logging.debug("Closing device")
            h.close()

        #except IOError as ex:
        #    logging.error(ex)
        #except Exception as ex:
        #    logging.error(ex)

    def __del__(self):
        pass
        #usbThread.join()

if __name__ == '__main__':
    import time
    a = Ut61(convertValues=True)
    #print "READ:"+str(a.currentReading)
    time.sleep(5)
    #print "READ:"+str(a.currentReading)
    time.sleep(5)
    #print "READ:"+str(a.currentReading)
