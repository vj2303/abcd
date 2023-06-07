import RPi.GPIO as GPIO
import time


Buzzer = 3
RUNNNING = True

GPIO.setmode(GPIO.BCM)

GPIO.setup(Buzzer, GPIO.OUT)

def BuzzerRing(val):
    GPIO.output(Buzzer, val)

try:
     while RUNNING:
          BuzzerRing(1)
          time.sleep(1)

          BuzzerRing(0)
          time.sleep(1)



except KeyboardInterrupt:
     
     RUNNING = False

finally:
     GPIO.cleanup()

          





