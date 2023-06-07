import RPi.GPIO as GPIO
import time

# Set up GPIO pin for the piezo element
GPIO.setmode(GPIO.BOARD)
PIEZO_PIN = 12  # GPIO pin for the piezo element

# Set up GPIO pin as output
GPIO.setup(PIEZO_PIN, GPIO.OUT)

# Function to play a tune
def play_tune():
    notes = [261, 294, 329, 349, 392, 440, 493, 523]  # Frequencies of the notes (C4 to C5)
    duration = 0.2  # Duration of each note in seconds
    
    # Play the tune
    for note in notes:
        GPIO.output(PIEZO_PIN, GPIO.HIGH)
        time.sleep(duration)
        GPIO.output(PIEZO_PIN, GPIO.LOW)
        time.sleep(0.1)  # Pause between notes

# Main loop to detect knocks
while True:
    # Detect a knock (you need to implement this part based on your specific sensor setup)
    knock_detected = False  # Placeholder, replace with actual detection code
    
    if knock_detected:
        print("Knock detected!")
        play_tune()

# Clean up GPIO pin
GPIO.cleanup()
