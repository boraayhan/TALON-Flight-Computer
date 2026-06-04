
#include "global/GlobalHeader.h"
#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager flightControlsManager;

void setup() {
    ControlSurface aileronLeft(
        4, "Aileron Left", AILERON, 90, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, +1);

    /*ControlSurface aileronRight(
        3, "Aileron Right", AILERON, 90, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, -1);

    ControlSurface elevatorLeft(2,
                                "Elevator Left",
                                ELEVATOR,
                                90,
                                -ELEVATOR_SERVO_POS_MAX_DEG,
                                ELEVATOR_SERVO_POS_MAX_DEG,
                                1);

    ControlSurface elevatorRight(1,
                                 "Elevator Right",
                                 ELEVATOR,
                                 90,
                                 -ELEVATOR_SERVO_POS_MAX_DEG,
                                 ELEVATOR_SERVO_POS_MAX_DEG,
                                 -1);
*/
    flightControlsManager.addControlSurface(aileronLeft);
        /*.addControlSurface(&aileronRight)
        .addControlSurface(&elevatorLeft)
        .addControlSurface(&elevatorRight);*/
    
    delay(1000);
    flightControlsManager.testControlSurfaces();
}

void loop() {}