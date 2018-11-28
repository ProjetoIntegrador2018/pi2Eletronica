#!/usr/bin/env python
#coding: utf8 

import threading
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)

i = 0

def printit():
global i
print i
threading.Timer(1.0, printit).start()

i = 0

printit()

# continue with the rest of your code

# Ereignis Prozedur für Eingang HIGH
def doIfHigh(channel):
# Zugriff auf Variable i ermoeglichen
global i
# Wenn Eingang HIGH ist, Ausgabe im Terminal erzeugen
#print str(i)
# Schleifenzaehler erhoehen
i = i + 1
GPIO.add_event_detect(11, GPIO.RISING, callback = doIfHigh) # bouncetime = 1)
