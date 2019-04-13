#!/usr/bin/env python

import serial
import scipy.interpolate

dbm = [-30,
-30,
-29,
-28,
-27,
-26,
-25,
-24,
-23,
-22,
-21,
-20,
-19,
-18,
-17,
-16,
-15,
-14,
-13,
-12,
-11,
-10,
-9,
-8,
-7,
-6,
-5,
-4,
-3,
-2,
-1,
0,
1,
1.442]
mV = [0,
0.25,
0.34,
0.44,
0.54,
0.7,
0.92,
1.17,
1.48,
1.89,
2.41,
3.03,
3.82,
4.82,
6.05,
7.53,
9.43,
11.81,
14.74,
18.33,
22.72,
28.03,
34.44,
42.17,
51.41,
61.43,
74.34,
89.49,
107.17,
127.78,
151.64,
179.05,
210.44,
225.8]


interp = scipy.interpolate.interp1d(mV, dbm)

ser = serial.Serial('/dev/ttyUSB0', baudrate=19200, bytesize=7,parity='O', stopbits=1, timeout=3)

def ut61e_get_mv(s):
    s.reset_input_buffer()
    line = s.readline()
    line = s.readline()
    #print(line)
    mv = float(line[1:6])/100
    return mv

def mV_to_dbm(mV):
    return interp(mV)
   
while True:
    mv = ut61e_get_mv(ser)
    dbm = mV_to_dbm(mv)
    print("%f;%f"%(dbm, mv))
