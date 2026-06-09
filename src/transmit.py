import struct
import serial
import time
import pygame

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=1)

pygame.init()
pygame.joystick.init()


THROTTLE_TRANSMIT_INTERVAL = 1
THROTTLE_STEP = 0.15

pRoll = 0
pPitch = 0
throttle = 0

plb = False
prb = False
paU = False
paD = False
paL = False
paR = False

tThrottle_ns = 0  # time of last throttle update, ns
tLb_ns = 0
if pygame.joystick.get_count() == 0:
    print("ERROR: No joystick found.")
    exit()


def transmit(id: int, p1: float, p2: float):
    payload = struct.pack("<iff", id, p1, p2)
    ser.write(payload)
    print(f"Tx ID: {id}, p1: {p1:.2f}, p2: {p2:.2f}")
    #time.sleep(0.05)


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

        # Trim (1 deg per arrow)
        aU = joystick.get_button(13) # Arrow up
        aD = joystick.get_button(14) # Arrow down
        aL = joystick.get_button(12) # Arrow left
        aR = joystick.get_button(15) # Arrow right
        if aU and not paU: # Arrow up
            transmit(1, 0, 1)
        if aD and not paD: # Arrow down
            transmit(1, 0, -1)
        if aL and not paL: # Arrow left
            transmit(1, -1, 0)
        if aR and not paR: # Arrow right
            transmit(1, 1, 0)
        paU = aU
        paD = aD
        paL = aL
        paR = aR

except Exception as err:
    print(f"Exiting program: {err}")
