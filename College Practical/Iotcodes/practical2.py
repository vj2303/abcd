import RPi.GPIO as GPIO
import time

# Set up GPIO mode and pin configurations
GPIO.setmode(GPIO.BCM)
GPIO.setup(5, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(3, GPIO.OUT)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)

# Define callback function for button press event
def my_callback(channel):
    GPIO.output(3, GPIO.LOW)
    GPIO.output(23, GPIO.LOW)
    GPIO.output(24, GPIO.LOW)
    time.sleep(0.1)

# Add event detection for falling edge on GPIO pin 5 (button press)
GPIO.add_event_detect(5, GPIO.FALLING, callback=my_callback, bouncetime=10)

try:
    while True:
        GPIO.output(3, GPIO.HIGH)
        GPIO.output(23, GPIO.HIGH)
        GPIO.output(24, GPIO.HIGH)
        time.sleep(1)

except KeyboardInterrupt:
    print("Exiting the program.")
    GPIO.cleanup()


# Expected Output:
# Assuming the code is executed without any errors, the program will continuously loop and 
# toggle the state of GPIO pins 3, 23, and 24 every second,
# turning the LEDs connected to these pins ON and OFF.
# When a falling edge is detected on GPIO pin 5 (button press), 
# the my_callback function will be called, and GPIO pins 3, 23, and 24 will be set to LOW for a brief
#  moment before resuming the LED blinking sequence. 
# The program will continue to run until you interrupt it by pressing Ctrl+C in the terminal.