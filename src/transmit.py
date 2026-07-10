import struct
import serial
import time
import pygame

# CONSTANTS
THROTTLE_TRANSMIT_INTERVAL_S = 1  # 1 default
THROTTLE_STEP = 0.15
TOGA_THROTTLE = 0.1  # 0.1 for testing, use 1 before flight
TRIM_STEP_DEG = 3

# If your input axes, like mine, don't go quite up to 100%...
MAX_PITCH_AXIS = 0.70
MAX_ROLL_AXIS = 0.75
MAX_YAW_AXIS = 0.75


ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=1)

pygame.init()
pygame.joystick.init()

# Previous axis states
pRoll = 0
pPitch = 0
pYaw = 0

throttle = 0

buttons = {}
pHat = (0, 0)

tThrottle_ns = 0  # time of last throttle update, ns
tLb_ns = 0

if pygame.joystick.get_count() == 0:
    print("ERROR: No joystick found.")
    exit()


def transmit(id: int, p1: float, p2: float, p3: float, p4: float):
    payload = struct.pack("<iffff", id, p1, p2, p3, p4)
    ser.write(payload)
    # print(f"Tx ID: {id}, p1: {p1:.2f}, p2: {p2:.2f}")
    time.sleep(0.05)


def buttonDown(button_id):
    current = joystick.get_button(button_id)
    previous = buttons.get(button_id, False)
    buttons[button_id] = current
    return current and not previous


def clamp(n, lower, upper):
    return max(lower, min(n, upper))


def axify(n):
    return clamp(n, -0.995, 0.995)


joystick = pygame.joystick.Joystick(0)
joystick.init()
print("Joystick:", joystick.get_name())

try:
    while True:
        pygame.event.get()
        if pygame.joystick.get_count() == 0:
            print("Joystick disconnected!!! Program quit for safety.")
            break
        tNow_ns = time.time_ns()

        # Joystick input
        roll = axify(joystick.get_axis(2) / MAX_ROLL_AXIS)
        pitch = axify(joystick.get_axis(1) / MAX_PITCH_AXIS)
        yaw = axify(joystick.get_axis(0) / MAX_ROLL_AXIS)

        lb = joystick.get_button(4)
        if buttonDown(4):
            throttle = max(0.0, throttle - THROTTLE_STEP)
        if buttonDown(5):
            throttle = min(1.0, throttle + THROTTLE_STEP)

        transmit(0, roll, pitch, yaw, throttle)

        # Flap
        # if buttonDown(0):  # Flap down (X)
        #     transmit(2, 1, 10) # 10 deg
        # if buttonDown(2): # Flap up (Triangle)
        #     transmit(2, 1, -10) # -10 deg

        # Trim (1 deg per arrow)
        hx, hy = joystick.get_hat(0)
        phx, phy = pHat
        trimRoll, trimPitch, trimYaw = 0, 0, 0

        if hy == 1 and phy != 1:  # Hat up
            trimPitch += TRIM_STEP_DEG
        if hy == -1 and phy != -1:  # Hat down
            trimPitch += -TRIM_STEP_DEG
        if hx == -1 and phx != -1:  # Hat left
            trimRoll -= TRIM_STEP_DEG
        if hx == 1 and phx != 1:  # Hat right
            trimRoll += TRIM_STEP_DEG

        pHat = (hx, hy)
        trimYaw = 0  # FIXME: read from central buttons
        if trimRoll + trimPitch + trimYaw > 0:
            transmit(1, trimRoll, trimPitch, trimYaw, 0)

except Exception as err:
    print(f"Exiting program: {err}")
