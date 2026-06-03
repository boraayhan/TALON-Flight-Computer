#include "main.h"

FlightControlsManager flightControlsManager;

int main() {
    ControlSurface aileronLeft(
        0, "Aileron Left", AILERON, 0, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, +1);

    ControlSurface aileronRight(
        1, "Aileron Right", AILERON, 0, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, -1);

    ControlSurface elevatorLeft(2,
                                "Elevator Left",
                                ELEVATOR,
                                0,
                                -ELEVATOR_SERVO_POS_MAX_DEG,
                                ELEVATOR_SERVO_POS_MAX_DEG,
                                1);

    ControlSurface elevatorRight(3,
                                 "Elevator Right",
                                 ELEVATOR,
                                 0,
                                 -ELEVATOR_SERVO_POS_MAX_DEG,
                                 ELEVATOR_SERVO_POS_MAX_DEG,
                                 -1);

    flightControlsManager.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        .addControlSurface(elevatorLeft)
        .addControlSurface(elevatorRight);

    while (true) {
        periodic();
    }
}

int periodic() {
    return 0;
}