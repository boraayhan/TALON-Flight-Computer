#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/sensors/CommunicationManager/CommunicationManager.h"
#include "global/GlobalHeader.h"

FlightControlsManager flightControlsManager;
CommunicationManager communicationManager(&flightControlsManager);

Motor motor(MOTOR_PIN);

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

                            

void setup() {
    communicationManager.init();
    flightControlsManager.addControlSurface(aileronLeft)
        .addControlSurface(aileronRight)
        .addControlSurface(elevator)
        .addControlSurface(rudder)
        .addMotor(motor);
    delay(1000);
    flightControlsManager.init();
    delay(500);
    flightControlsManager.setThrottle(0.0f);
}

void loop() {
    communicationManager.periodic();
    flightControlsManager.periodic();
    //autopilot.periodic();
}