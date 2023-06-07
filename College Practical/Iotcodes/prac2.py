import RPi.GPIO as GPIO
import time

# Set up GPIO pins for the lights
GPIO.setmode(GPIO.BOARD)
GREEN_PIN = 11  # GPIO pin for green light
YELLOW_PIN = 13  # GPIO pin for yellow light
RED_PIN = 15  # GPIO pin for red light

# Set up GPIO pins as output
GPIO.setup(GREEN_PIN, GPIO.OUT)
GPIO.setup(YELLOW_PIN, GPIO.OUT)
GPIO.setup(RED_PIN, GPIO.OUT)

# Function to blink the green light
def blink_green_light():
    GPIO.output(GREEN_PIN, GPIO.HIGH)  # Turn on the green light
    time.sleep(1)  # Wait for 1 second
    GPIO.output(GREEN_PIN, GPIO.LOW)  # Turn off the green light
    time.sleep(1)  # Wait for 1 second

# Function to illuminate the green light
def illuminate_green_light():
    GPIO.output(GREEN_PIN, GPIO.HIGH)  # Turn on the green light

# Function to illuminate the yellow light
def illuminate_yellow_light():
    GPIO.output(YELLOW_PIN, GPIO.HIGH)  # Turn on the yellow light

# Function to illuminate the red light
def illuminate_red_light():
    GPIO.output(RED_PIN, GPIO.HIGH)  # Turn on the red light

# Main loop to get user input
while True:
    user_input = input("Enter 'b' to blink green light, 'g' to illuminate green light, 'y' to illuminate yellow light, or 'r' to illuminate red light: ")
    
    if user_input == 'b':
        blink_green_light()
    elif user_input == 'g':
        illuminate_green_light()
    elif user_input == 'y':
        illuminate_yellow_light()
    elif user_input == 'r':
        illuminate_red_light()
    else:
        print("Invalid input. Please try again.")

# Clean up GPIO pins
GPIO.cleanup()
