import struct
import serial
import time
import pygame

# CONSTANTS
THROTTLE_TRANSMIT_INTERVAL_NS = 1
THROTTLE_STEP = 0.15
TOGA_THROTTLE = 0.1  # 0.1 for testing, use 1 before flight
TRIM_STEP_DEG = 3

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=1)

pygame.init()
pygame.joystick.init()

# Previous axis states
pRoll = 0
pPitch = 0
throttle = 0

buttons = {}
pHat = (0, 0)

tThrottle_ns = 0  # time of last throttle update, ns
tLb_ns = 0

if pygame.joystick.get_count() == 0:
    print("ERROR: No joystick found.")
    exit()


def transmit(id: int, p1: float, p2: float):
    payload = struct.pack("<iff", id, p1, p2)
    ser.write(payload)
    print(f"Tx ID: {id}, p1: {p1:.2f}, p2: {p2:.2f}")
    time.sleep(0.05)


def buttonDown(button_id):
    current = joystick.get_button(button_id)
    previous = buttons.get(button_id, False)
    buttons[button_id] = current
    return current and not previous


joystick = pygame.joystick.Joystick(0)
joystick.init()
print("Joystick:", joystick.get_name())

try:
    while True:
        pygame.event.get()
        tNow_ns = time.time_ns()

        # Joystick input
        roll = joystick.get_axis(0)
        pitch = joystick.get_axis(1)
        if abs(roll - pRoll) > 0.05 or abs(pitch - pPitch) > 0.05:
            transmit(0, roll, pitch)
            pRoll = roll
            pPitch = pitch

        # Throttle
        lb = joystick.get_button(4)
        if buttonDown(4):
            throttle = max(0.0, throttle - THROTTLE_STEP)
            transmit(3, throttle, 0)
            tLb_ns = tNow_ns

        if buttonDown(5):
            throttle = min(1.0, throttle + THROTTLE_STEP)
            transmit(3, throttle, 0)

        if lb and (tNow_ns - tLb_ns) > 5e8:
            transmit(3, 0, 0)
            throttle = 0
            tLb_ns = tNow_ns
            tThrottle_ns = tNow_ns

        if tNow_ns - tThrottle_ns > THROTTLE_TRANSMIT_INTERVAL_NS * 1e9:
            transmit(3, throttle, 0)
            tThrottle_ns = tNow_ns

        # Flap
        # if buttonDown(0):  # Flap down (X)
        #     transmit(2, 1, 10) # 10 deg
        # if buttonDown(2): # Flap up (Triangle)
        #     transmit(2, 1, -10) # -10 deg

        # Trim (1 deg per arrow)
        hx, hy = joystick.get_hat(0)
        phx, phy = pHat

        if hy == 1 and phy != 1:  # Hat up
            transmit(1, 0, TRIM_STEP_DEG)
            transmit(0, 0, 0)
        if hy == -1 and phy != -1:  # Hat down
            transmit(1, 0, -TRIM_STEP_DEG)
            transmit(0, 0, 0)
        if hx == -1 and phx != -1:  # Hat left
            transmit(1, -TRIM_STEP_DEG, 0)
            transmit(0, 0, 0)
        if hx == 1 and phx != 1:  # Hat right
            transmit(1, TRIM_STEP_DEG, 0)
            transmit(0, 0, 0)

        pHat = (hx, hy)

        # TOGA mode
        if buttonDown(9):
            transmit(4, TOGA_THROTTLE, 0)
            throttle = TOGA_THROTTLE
            
        # Rudder
        if buttonDown(13):
            transmit(4, TOGA_THROTTLE, 0)

        if pygame.joystick.get_count() == 0:
            print("Joystick disconnected!!! Program quit for safety.")
            break

except Exception as err:
    print(f"Exiting program: {err}")
