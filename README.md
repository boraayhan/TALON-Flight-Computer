# TALON Flight Computer (Under Development)
The **T**rim, **A**uto **L**and, **O**dometry, and **N**avigation flight computer is a comprehensive and customizable low-cost flight software package designed to be integrated into Class 1 Unmanned Aerial Vehicles (UAVs).
## Features
![System Architecture Diagram](/SystemDiagram.svg)
### Current Core Features
* 3-axis (pitch, roll, yaw) flight control surface actuation & throttle control from remote joystick inputs.
* 3-axis flight control surface (aileron, elevator, rudder) trim
* Support for UAVs with any configuration of ailerons/elevators/rudders, and support for UAVs with multiple motors (or no motors at all!)
* Take-off, go-around (TOGA) autopilot mode, which can triggered by the pilot to set a climb attitude, allowing the pilot to "hand-launch" their UAV by ensuring positive rate after takeoff.
### Current Safety Features
* Automatic idling of throttle and setting of a glidepath after pilot input controller disconnects, radio fails, or a transmitter error is detected, for more than 1000ms, in order to minimize damage to the UAV after such an event.
* Filtering and dismissal of erratic inputs stemming from radio packets being dropped

# Contributing
## Project-Wide Conventions
These conventions are followed throughout the project, unless otherwise specified.
#### Units
* All units are in SI units (meters, seconds, and kilograms) and their respective derived units (e.g. m/(s^2) for acceleration)
#### Directions and Coordinates
* All units of heading/bearing are expressed in degrees, represented from 0 to 360 degrees clockwise. 0 degrees represents "North", and 90 degrees represents "East".
* For circular paths, a "LEFT" circle represents a counterclockwise  path, and a "RIGHT" circle represents a clockwise path.
* All coordinates and flight positions are Vector3 objects of the following form, unless marked "Local":
  * x: East-West displacement, in meters, from the calibrated "zero" position, with +X being "East"
  * y: North-South displacement, in meters, from the calibrated "zero" position, with +Y being "North"
  * z: Altitude, in meters, relative to the calibrated "zero" position, with +Z representing an increase in altitude.
* A Vector3 designated "local" is relative to aircraft's velocity vector with the following conventions:
  * +x: Horizontal axis spanning from aircraft's tail to nose
  * +y: Horizontal axis spanning from left (port) wingtip to right (starboard) wingtip
  * +z: Horizontal axis spanning from aircraft's **belly to its celing** ("up", unlike the convention specified in MIL-STD-810G, fig. 513.7-1, and the right-hand rule, which describe +z as pointing towards ground at level flight)
