import RPi.GPIO as GPIO

# Pin definitions
LED_PIN_1 = 2  # First LED connected to GPIO pin 2
LED_PIN_2 = 3  # Second LED connected to GPIO pin 3
LED_PIN_3 = 4  # Third LED connected to GPIO pin 4
LED_PIN_4 = 5  # Fourth LED connected to GPIO pin 5

# Set up GPIO mode and warnings
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

# Set up LED pins as outputs
GPIO.setup(LED_PIN_1, GPIO.OUT)
GPIO.setup(LED_PIN_2, GPIO.OUT)
GPIO.setup(LED_PIN_3, GPIO.OUT)
GPIO.setup(LED_PIN_4, GPIO.OUT)

def blink_leds(led_pins):
    # Blink the LEDs
    for pin in led_pins:
        GPIO.output(pin, GPIO.HIGH)
    GPIO.wait_for_edge(button_pin, GPIO.FALLING)
    for pin in led_pins:
        GPIO.output(pin, GPIO.LOW)

def illuminate_leds(led_pins):
    # Illuminate the LEDs
    for pin in led_pins:
        GPIO.output(pin, GPIO.HIGH)

def turn_off_leds():
    # Turn off all LEDs
    GPIO.output(LED_PIN_1, GPIO.LOW)
    GPIO.output(LED_PIN_2, GPIO.LOW)
    GPIO.output(LED_PIN_3, GPIO.LOW)
    GPIO.output(LED_PIN_4, GPIO.LOW)

# Main loop
try:
    while True:
        user_input = input("Enter 'b' to blink two LEDs, 'g' to illuminate next two LEDs, or 'y' to illuminate all four LEDs: ")
        
        # Clear previous LED states
        turn_off_leds()

        # Check user input and control LEDs accordingly
        if user_input == 'b':
            blink_leds([LED_PIN_1, LED_PIN_2])
        elif user_input == 'g':
            blink_leds([LED_PIN_3, LED_PIN_4])
        elif user_input == 'y':
            illuminate_leds([LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4])

except KeyboardInterrupt:
    # Clean up GPIO pins on program exit
    GPIO.cleanup()
