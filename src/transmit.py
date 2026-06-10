import struct
import serial
import time
import pygame

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=1)

pygame.init()
pygame.joystick.init()


THROTTLE_TRANSMIT_INTERVAL = 1
THROTTLE_STEP = 0.15
TOGA_THROTTLE = 1.0 # 0.1 for testing, use 1 before flight
TRIM_STEP = 3

pRoll = 0
pPitch = 0
throttle = 0

plb = False
prb = False

# ptri = False
# px = False

phU = False
phD = False
phL = False
phR = False

pOptionsButton = False

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
        rb = joystick.get_button(5)
        if lb and not plb:
            throttle = max(0.0, throttle - THROTTLE_STEP)
            transmit(3, throttle, 0)
            tLb_ns = tNow_ns
        if rb and not prb:
            throttle = min(1.0, throttle + THROTTLE_STEP)
            transmit(3, throttle, 0)
        if lb and (tNow_ns - tLb_ns) > 5e8:
            transmit(3, 0, 0)
            throttle = 0
            tLb_ns = tNow_ns
            tThrottle_ns = tNow_ns
        if tNow_ns - tThrottle_ns > THROTTLE_TRANSMIT_INTERVAL * 1e9:
            transmit(3, throttle, 0)
            tThrottle_ns = tNow_ns
        plb = lb
        prb = rb

        # Flap
        # x = joystick.get_button(0)
        # tri = joystick.get_button(2)
        # if x and not px:  # Flap down
        #     transmit(2, 1, 10) # 10 deg
        # if tri and not ptri: # Flap up
        #     transmit(2, 1, -10) # -10 deg
        # px = x
        # ptri = tri

        # Trim (1 deg per arrow)
        hx, hy = joystick.get_hat(0)
        if hy == 1 and not phU:  # Hat up
            transmit(1, 0, TRIM_STEP)
            transmit(0, 0, 0)
        if hy == -1 and not phD:  # Hat down
            transmit(1, 0, -TRIM_STEP)
            transmit(0, 0, 0)
        if hx == -1 and not phL:  # Hat left
            transmit(1, -TRIM_STEP, 0)
            transmit(0, 0, 0)
        if hx == 1 and not phR:  # Hat right
            transmit(1, TRIM_STEP, 0)
            transmit(0, 0, 0)
        phU = hy == 1
        phD = hy == -1
        phL = hx == -1
        phR = hx == 1

        # TOGA mode
        optionsButton = joystick.get_button(9)
        if optionsButton and not pOptionsButton:
            transmit(4, TOGA_THROTTLE, 0)
            throttle = TOGA_THROTTLE
        pOptionsButton = optionsButton
        
        if pygame.joystick.get_count() == 0:
            print("Joystick disconnected!!! Program quit for safety.")
            break

except Exception as err:
    print(f"Exiting program: {err}")
