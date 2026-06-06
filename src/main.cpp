
#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "global/GlobalHeader.h"
#include "data/sensors/CommunicationManager/CommunicationManager.h"

FlightControlsManager flightControlsManager;
CommunicationManager communicationManager(&flightControlsManager);

ControlSurface aileronLeft(
        AILERON_LEFT_PIN, "Aileron Left", AILERON, 90, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, +1);
    ControlSurface aileronRight(
        AILERON_RIGHT_PIN, "Aileron Right", AILERON, 90, -AILERON_SERVO_POS_MAX_DEG, AILERON_SERVO_POS_MAX_DEG, -1);

    /*ControlSurface elevatorLeft(ELEVATOR_LEFT_PIN,
                                "Elevator Left",
                                ELEVATOR,
                                90,
                                -ELEVATOR_SERVO_POS_MAX_DEG,
                                ELEVATOR_SERVO_POS_MAX_DEG,
                                1);
    */
    /*ControlSurface elevatorRight(ELEVATOR_RIGHT_PIN,
                                 "Elevator Right",
                                 ELEVATOR,
                                 90,
                                 -ELEVATOR_SERVO_POS_MAX_DEG,
                                 ELEVATOR_SERVO_POS_MAX_DEG,
                                 -1);
    */
                                 
void setup() {
    communicationManager.init();
    Motor motorLeft(MOTOR_LEFT_PIN);
    Motor motorRight(MOTOR_RIGHT_PIN);

    flightControlsManager.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        //.addControlSurface(elevatorLeft)
        //.addControlSurface(elevatorRight)
        .addMotor(motorLeft)
        .addMotor(motorRight);
    
    delay(1000);
    flightControlsManager.testControlSurfaces();
    flightControlsManager.setThrottle(0.0f);
}

void loop() {
    communicationManager.periodic();
    flightControlsManager.updateThrottle();
}