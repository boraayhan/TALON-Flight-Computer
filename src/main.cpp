#include "src/main.h"

FlightControlsManager flightControlsManager;

int main() {
    // clang-format off
ControlSurface aileronLeft(0,
                               "Aileron Left",
                               AILERON,
                               0,
                               AILERON_SERVO_POS_MIN_DEG,
                               AILERON_SERVO_POS_MAX_DEG,
                               +1);

    ControlSurface aileronRight(1,
                                "Aileron Right",
                                AILERON,
                                0,
                                AILERON_SERVO_POS_MIN_DEG,
                                AILERON_SERVO_POS_MAX_DEG,
                                -1);

    ControlSurface elevatorLeft(2,
                                "Elevator Left",
                                ELEVATOR,
                                0,
                                ELEVATOR_SERVO_POS_MIN_DEG,
                                ELEVATOR_SERVO_POS_MAX_DEG,
                                1);

    ControlSurface elevatorRight(3,
                                 "Elevator Right",
                                 ELEVATOR,
                                 0,
                                 ELEVATOR_SERVO_POS_MIN_DEG,
                                 ELEVATOR_SERVO_POS_MAX_DEG,
                                 -1);

    ControlSurface rudder(4,
                          "Rudder",
                          RUDDER,
                          0,
                          RUDDER_SERVO_POS_MIN_DEG,
                          RUDDER_SERVO_POS_MAX_DEG,
                          1);
    // clang-format on

    flightControlsManager.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        .addControlSurface(elevatorLeft)
        .addControlSurface(elevatorRight)
        .addControlSurface(rudder);

    while (true) {
        periodic();
    }
}

int periodic() {}