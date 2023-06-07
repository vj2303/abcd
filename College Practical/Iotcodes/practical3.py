import time
import RPi.GPIO as GPIO

RUNNING = True

HIGH = 1
LOW = 0
DetectPin = 5

def InitSystem():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(DetectPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def DetectPerson():
    while True:
        input_state = GPIO.input(DetectPin)
        time.sleep(0.3)
        if input_state == 0:
            return LOW
        else:
            return HIGH

try:
    print("\nCounting using IR LED")
    print("-----------------------------------------------\n")
    InitSystem()
    count = 0
    while RUNNING:
        state = DetectPerson()
        if state == HIGH:
            count += 1
            print("person count = %d" % count)

except KeyboardInterrupt:
    print("Stopping Elevator")

finally:
    GPIO.cleanup()






# Expected Output:
# Assuming the code is executed without any errors and there is a functioning IR LED and sensor connected to GPIO pin 5 on the Raspberry Pi, 
# the program will continuously loop and count the number of times a person is detected. Whenever the sensor detects a person, the count will be incremented by 1, 
# and the updated count will be printed.
# The program will continue to run until you interrupt it by pressing Ctrl+C in the terminal.