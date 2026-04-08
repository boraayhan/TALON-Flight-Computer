#include "data/data_structures/CommunicationPayload/CommunicationPayload.h"

JoystickInput::JoystickInput(double xA, double yA) {
  type = CommType::JoystickInput;
  this->xAxis = xA;
  this->yAxis = yA;
}

ThrottleInput::ThrottleInput(double throttle) {
  type = CommType::ThrottleInput;
  this->throttle = throttle;
}

FlapInput::FlapInput(double flap) {
  type = CommType::FlapInput;
  this->flapAngleDegrees = flap;
}

JSONWrite::JSONWrite(const std::string json, std::string path) {
  type = CommType::JSONWrite;
  this->json = json;
  this->path = path;
}

std::variant<JoystickInput, ThrottleInput, FlapInput, JSONWrite> CommunicationVariant;