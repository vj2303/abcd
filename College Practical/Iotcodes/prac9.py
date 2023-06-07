import RPi.GPIO as GPIO
import time

# Pin definitions
LED_PIN_1 = 2  # First LED connected to GPIO pin 2
LED_PIN_2 = 3  # Second LED connected to GPIO pin 3

# Delay between LED state changes (in seconds)
DELAY_SEC = 0.5

# Set up GPIO mode and warnings
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

# Set up LED pins as outputs
GPIO.setup(LED_PIN_1, GPIO.OUT)
GPIO.setup(LED_PIN_2, GPIO.OUT)

try:
    while True:
        # Alternate blinking of LED 1 and LED 2
        GPIO.output(LED_PIN_1, GPIO.HIGH)
        GPIO.output(LED_PIN_2, GPIO.LOW)
        time.sleep(DELAY_SEC)
        GPIO.output(LED_PIN_1, GPIO.LOW)
        GPIO.output(LED_PIN_2, GPIO.HIGH)
        time.sleep(DELAY_SEC)

except KeyboardInterrupt:
    # Clean up GPIO pins on program exit
    GPIO.cleanup()
