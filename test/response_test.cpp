
#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "global/GlobalHeader.h"

FlightControlsManager flightControlsManager;

void setup() {
    ControlSurface aileronLeft(
        1, "Aileron Left", AILERON, 90, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, +1);
    ControlSurface aileronRight(
        2, "Aileron Right", AILERON, 90, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, -1);

    ControlSurface elevatorLeft(3,
                                "Elevator Left",
                                ELEVATOR,
                                90,
                                -ELEVATOR_SERVO_POS_MAX_DEG,
                                ELEVATOR_SERVO_POS_MAX_DEG,
                                1);

    ControlSurface elevatorRight(4,
                                 "Elevator Right",
                                 ELEVATOR,
                                 90,
                                 -ELEVATOR_SERVO_POS_MAX_DEG,
                                 ELEVATOR_SERVO_POS_MAX_DEG,
                                 -1);
    Motor motorLeft(5);
    Motor motorRight(6);

    flightControlsManager.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        .addControlSurface(elevatorLeft)
        .addControlSurface(elevatorRight)
        .addMotor(motorLeft)
        .addMotor(motorRight);
    
    delay(1000);
    flightControlsManager.testControlSurfaces();
}

void loop() {}