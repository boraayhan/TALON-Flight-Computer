# TALON Flight Computer (Under Development)
The **T**rim, **A**uto **L**and, **O**dometry, and **N**avigation flight computer is a comprehensive and customizable low-cost flight software package designed to be integrated into Class 1 Unmanned Aerial Vehicles (UAVs).

## Current Core Features
* 3-axis (pitch, roll, yaw) flight control surface actuation & throttle control from remote joystick inputs.
* 3-axis flight control surface (aileron, elevator, rudder) trim
* Support for UAVs with any configuration of ailerons/elevators/rudders, and support for UAVs with multiple motors (or no motors at all!)
* Take-off, go-around (TOGA) autopilot mode, which can triggered by the pilot to set a climb attitude, allowing the pilot to "hand-launch" their UAV by ensuring positive rate after takeoff.
## Current Safety Features
* Automatic idling of throttle and setting of a glidepath after pilot input controller disconnects, radio fails, or a transmitter error is detected, for more than 1000ms, in order to minimize damage to the UAV after such an event.
* Filtering and dismissal of erratic inputs stemming from radio packets being dropped
