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
pThrottle = 0
throttle = 0

plb = False
prb = False

tThrottle_ns = 0 # time of last throttle update, ns
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

        # Joystick input
        roll = joystick.get_axis(0)
        pitch = joystick.get_axis(1)
        if abs(roll - pRoll) > 0.05 or abs(pitch - pPitch) > 0.05:
            transmit(0, roll, pitch)
            pRoll = roll
            pPitch = pitch
        if time.time_ns() - tThrottle_ns > THROTTLE_TRANSMIT_INTERVAL * 1e9:
            transmit(3, throttle, 0)
            tThrottle_ns = time.time_ns()

        # Throttle
        lb = joystick.get_button(4)
        rb = joystick.get_button(5)

        if lb and not plb:
            throttle = max(0.0, throttle - THROTTLE_STEP)
            transmit(3, throttle, 0)
            pThrottle = throttle
            tLb_ns = time.time_ns()

        if rb and not prb:
            throttle = min(1.0, throttle + THROTTLE_STEP)
            transmit(3, throttle, 0)
            pThrottle = throttle

        if lb and (time.time_ns() - tLb_ns) > 5e8:
            transmit(3, 0, 0)
            throttle = 0
            pThrottle = 0
            tLb_ns = time.time_ns()
        plb = lb
        prb = rb

except Exception as err:
    print(f"Exiting program: {err}")
