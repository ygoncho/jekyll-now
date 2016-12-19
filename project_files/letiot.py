#!/usr/bin/python
import sys
import serial
import time


portwifi = "/dev/tty.usbserial-FT9KZ5BU"
speedwifi = 115200
portfab =  "/dev/tty.usbserial-FT94TLAR"
speedfab = 9600
ser_wifi = serial.Serial(portwifi, speedwifi)
ser_wifi.setDTR()
ser_fab = serial.Serial(portfab, speedfab)
ser_fab.setDTR()
time.sleep(5)

ser_wifi.flushInput()
ser_wifi.flushOutput()

ser_wifi.write(b'=wifi.sta.getip()\r\n')
time.sleep(1) # wait a sec
myip = ""
while (ser_wifi.inWaiting()):
    byte = ser_wifi.read();
    myip += byte
    sys.stdout.write(byte);
sys.stdout.write('\n')
myip = myip.split( )[1].split(' ')[0]
print myip
ser_fab.write(myip+'\r\n')
entered = 0
while(1):
    while (ser_fab.inWaiting()):
        byte = ser_fab.read();
        sys.stdout.write(byte);
        entered = 1;
        time.sleep(0.1) # wait a bit
    if (entered):
        sys.stdout.write('\n')
        entered = 0;

