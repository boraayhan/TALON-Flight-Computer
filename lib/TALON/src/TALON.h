#pragma once

#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/sensors/CommunicationManager/CommunicationManager.h"
#include "global/GlobalHeader.h"

struct FlightState {
    Vector3 velocity; // Meters per second
    Vector3 position; // Meters, relative to starting position
    FlightCommand latestFlightCommand;
    TrimCommand trim;
};

class TALON {
  public:
    TALON();
    void init();
    void periodic();
    TALON &addControlSurface(ControlSurface &s);
    TALON &addMotor(Motor &m);
    const FlightState &getFlightState() const;
  private:
    FlightControlsManager flightControlsManager;
    Autopilot autopilot;
    CommunicationManager communicationManager;
    FlightState flightState;
};

/*
Some notes for myself. I didn't have a pen and paper handy (undeniably the two best engineering tools), so here we are. Please disregard:

Control priority:
Components/commands:
* Communication Manager: Intake antenna data, call on EITHER autopilot or sends packets of FlightCommand to flightControlsManager
* NavigationPlanner: Purely a math utility. Given set of flight params, desired inputs, etc, from AP, return f(x,y,z). No periodic(), only run when called by AP
* Control Surface / Motor / Etc: Given simple angles/duty cycle, command physical components
* main.cpp: Instatiate TALON, add surfaces, call talon.init and talon.periodic()
* FlightControlsManager: Intake "FlightCommand", send simple motion commands to control surfaces, which are defined by user calling .addSurface() on TALON.h object, ...
* Autopilot (AP): From a SysEng perspective, mirrors how the pilot sends commands to the rest of TALON, only difference being that AP is automated. CommManager sends desired state/params (circle this coordinate: [x,y,h], or autoland on rwy @ blah blah blah). Has periodic(). Reads from Flight
* TALON: Top level storage for all flight vars. Holds one reference to each applicable subcomponent (manager, etc) and links them. Has functions for user access (.addSurface) that call each subcomponent. Holds the master FlightParams (name WIP) struct containing vel, pos, etc.
*/