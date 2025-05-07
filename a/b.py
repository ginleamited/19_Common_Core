import pyautogui
import mouse
import sys
import time
import subprocess
from pynput import keyboard

# Accept input as a float to handle fractions of an hour
length = float(input("Enter how long in hours (e.g., 0.5 for half an hour): "))

pyautogui.FAILSAFE = False
width, height = pyautogui.size()

# Convert hours to seconds, including fractions
length_second = length * 3600
start = time.time()

stop_program = False
nody_process = None  # To store the nody-greeter process reference
pressed_keys = set()

def on_press(key):
    global stop_program
    pressed_keys.add(key)

    # Detect Shift + '='
    if keyboard.Key.shift in pressed_keys and key == keyboard.KeyCode.from_char('='):
        print("Shift + = detected. Stopping program...")
        stop_program = True

def on_release(key):
    # Remove key from the set when released
    if key in pressed_keys:
        pressed_keys.remove(key)

def main(move_size):
    global stop_program, nody_process

    # Start the nody-greeter process
    nody_process = subprocess.Popen(["nody-greeter"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Start a listener for key presses
    listener = keyboard.Listener(on_press=on_press, on_release=on_release)
    listener.start()

    while True:
        if stop_program:
            # Terminate the nody-greeter process
            if nody_process:
                nody_process.terminate()
                nody_process.wait()
            mouse.move(3734, 19)
            time.sleep(1)
            pyautogui.click()
            sys.exit()

        mouse.move(width, height)
        mouse.move(width, height + move_size)
        mouse.move(width + move_size, height - move_size)
        mouse.move(width + move_size, height)

        if time.time() - start >= length_second:
            if nody_process:
                nody_process.terminate()
                nody_process.wait()
            mouse.move(3734, 19)
            time.sleep(1)
            pyautogui.click()
            sys.exit()

main(2)
