#!/usr/bin/env python

import sys,time,serial
import Tkinter
from select import *
import sys
from PIL import Image, ImageTk

port = "/dev/tty.usbserial-A700HM92"
speed = 115200

# Serial
ser = serial.Serial(port,speed, timeout=0, writeTimeout=0)
ser.setDTR()

# Flush buffers
ser.flushInput()
ser.flushOutput()

def setLED():
   ser.write('y')

def clearLED():
   ser.write('n')

top = Tkinter.Tk()
imageOn = ImageTk.PhotoImage(Image.open("on.bmp"))
imageOff = ImageTk.PhotoImage(Image.open("off.bmp"))
B = Tkinter.Button(top, text ="Set LED", command = setLED)
B2 = Tkinter.Button(top, text ="Clear LED", command = clearLED)
B.pack()
B2.pack()
panel = Tkinter.Label(top, image = imageOff)
panel.pack()
def getButtonStatus():
    while(1):
        tmpbutton_status = ser.read()
        if (len(tmpbutton_status) == 0):
            break
        if (tmpbutton_status != '0' and tmpbutton_status != '1'):
            break
        else:
            return tmpbutton_status;
        return 'e'

def setButtonStatus(status):
    if (status == '1'):
        panel.configure(image = imageOn)
        panel.image = imageOn
    elif (status == '0'):
        panel.configure(image = imageOff)
        panel.image = imageOff
    else:
        return
    panel.update()
           
while(1):
    top.update_idletasks()
    status = getButtonStatus();
    setButtonStatus(status);
    top.update()

