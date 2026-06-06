import struct
import serial
import time
import pygame

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=1)

pygame.init()
pygame.joystick.init()

pRoll = 0
pPitch = 0
pThrottle = 0

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
        if abs(roll - pRoll) > 0.07 or abs(pitch - pPitch) > 0.07:
            transmit(0, roll, pitch)

            pRoll = roll
            pPitch = pitch

        # Throttle
        throttle = (-joystick.get_axis(2) + 1) / 2
        if abs(throttle - pThrottle) > 0.07:
            transmit(3, throttle, 0)
            pThrottle = throttle
            isThrottleZero = False
        if(throttle <= 0.07 and pThrottle > 0.07):
            transmit(3, 0, 0)
            pThrottle = 0

        hat_raw = joystick.get_hat(0)
        hat = (int(hat_raw[0]), int(hat_raw[1]))
                
except Exception as err:
    print(f"Exiting program: {err}")