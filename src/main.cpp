#include "TALON.h"

ControlSurface aileronLeft(AILERON_LEFT_PIN,
                           "Aileron Left",
                           AILERON,
                           60,
                           -AILERON_SERVO_POS_MAX_DEG,
                           AILERON_SERVO_POS_MAX_DEG,
                           -1);
ControlSurface aileronRight(AILERON_RIGHT_PIN,
                            "Aileron Right",
                            AILERON,
                            80,
                            -AILERON_SERVO_POS_MAX_DEG,
                            AILERON_SERVO_POS_MAX_DEG,
                            -1);

ControlSurface elevator(ELEVATOR_PIN,
                        "Elevator",
                        ELEVATOR,
                        80,
                        -ELEVATOR_SERVO_POS_MAX_DEG,
                        ELEVATOR_SERVO_POS_MAX_DEG,
                        1);

ControlSurface rudder(RUDDER_PIN,
                      "Rudder",
                      RUDDER,
                      80,
                      -RUDDER_SERVO_POS_MAX_DEG,
                      RUDDER_SERVO_POS_MAX_DEG,
                      1);

Motor motor(MOTOR_PIN);
TALON talon;

void setup() {
    talon.init();
    talon.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        .addControlSurface(elevator)
        .addControlSurface(rudder)
        .addMotor(motor);
}

void loop() { talon.periodic(); }