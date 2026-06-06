#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/sensors/CommunicationManager/CommunicationManager.h"
#include "global/GlobalHeader.h"

FlightControlsManager flightControlsManager;
CommunicationManager communicationManager(&flightControlsManager);

Motor motorLeft(MOTOR_LEFT_PIN);
Motor motorRight(MOTOR_RIGHT_PIN);

ControlSurface aileronLeft(AILERON_LEFT_PIN, "Aileron Left", AILERON, 90,
                           -AILERON_SERVO_POS_MAX_DEG,
                           AILERON_SERVO_POS_MAX_DEG, +1);
ControlSurface aileronRight(AILERON_RIGHT_PIN, "Aileron Right", AILERON, 90,
                            -AILERON_SERVO_POS_MAX_DEG,
                            AILERON_SERVO_POS_MAX_DEG, -1);

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
  flightControlsManager.addControlSurface(aileronLeft)
      .addControlSurface(aileronRight)
      //.addControlSurface(elevatorLeft)
      //.addControlSurface(elevatorRight)
      .addMotor(motorLeft)
      .addMotor(motorRight);
  delay(1000);
  // flightControlsManager.testControlSurfaces();
  flightControlsManager.init();
  delay(500);
  flightControlsManager.setThrottle(0.0f);
}

void loop() {
  communicationManager.periodic();
  flightControlsManager.updateThrottle();
}