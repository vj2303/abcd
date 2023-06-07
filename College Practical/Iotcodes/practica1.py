import time
import RPi.GPIO as GPIO

led_pins = [20, 21, 22, 23, 24, 25, 26, 27]

GPIO.setmode(GPIO.BCM)

for pin in led_pins:
    GPIO.setup(pin, GPIO.OUT)

try:
    # Turning on all LEDs initially
    for pin in led_pins:
        GPIO.output(pin, GPIO.HIGH)

    while True:
        for pin in led_pins:
            GPIO.output(pin, GPIO.HIGH)
            time.sleep(0.2)
            GPIO.output(pin, GPIO.LOW)
            time.sleep(0.2)

except KeyboardInterrupt:
    print("Exiting the program.")

finally:
    GPIO.cleanup()




# Expected Output:
# The LEDs connected to the GPIO pins will blink in sequence, with each LED turning on for 0.2 seconds and then turning off for 0.2 seconds.
# This pattern will repeat until you interrupt the program by pressing Ctrl+C in the terminal.
































