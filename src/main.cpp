#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/sensors/CommunicationManager/CommunicationManager.h"
#include "global/GlobalHeader.h"

FlightControlsManager flightControlsManager;
Autopilot autopilot(&flightControlsManager);
CommunicationManager communicationManager(&flightControlsManager, &autopilot);

Motor motorLeft(MOTOR_LEFT_PIN);
Motor motorRight(MOTOR_RIGHT_PIN);

ControlSurface aileronLeft(AILERON_LEFT_PIN,
                           "Aileron Left",
                           AILERON,
                           60,
                           -AILERON_SERVO_POS_MAX_DEG,
                           AILERON_SERVO_POS_MAX_DEG,
                           +1);
ControlSurface aileronRight(AILERON_RIGHT_PIN,
                            "Aileron Right",
                            AILERON,
                            80,
                            -AILERON_SERVO_POS_MAX_DEG,
                            AILERON_SERVO_POS_MAX_DEG,
                            +1);

ControlSurface elevator(ELEVATOR_LEFT_PIN,
                            "Elevator Left",
                            ELEVATOR,
                            50,
                            -ELEVATOR_SERVO_POS_MAX_DEG,
                            ELEVATOR_SERVO_POS_MAX_DEG,
                            1);

void setup() {
    communicationManager.init();
    flightControlsManager.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        .addControlSurface(elevator)
        .addMotor(motorLeft)
        .addMotor(motorRight);
    delay(1000);
    flightControlsManager.init();
    delay(500);
    flightControlsManager.setThrottle(0.0f);
}

void loop() {
    communicationManager.periodic();
    //autopilot.periodic();
}