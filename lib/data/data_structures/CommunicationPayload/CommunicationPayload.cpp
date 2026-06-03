#include "data/data_structures/CommunicationPayload/CommunicationPayload.h"

JoystickInput::JoystickInput(float xA, float yA) {
  this->type = CommType::JoystickInput;
  this->xAxis = xA;
  this->yAxis = yA;
}

ThrottleInput::ThrottleInput(float throttle) {
  this->type = CommType::ThrottleInput;
  this->throttle = throttle;
}

FlapInput::FlapInput(float flap) {
  this->type = CommType::FlapInput;
  this->flapAngleDegrees = flap;
}

JSONWrite::JSONWrite(const String json, String path) {
  this->type = CommType::JSONWrite;
  this->json = json;
  this->path = path;
}

YawInput::YawInput(float zA) {
  this->type = CommType::YawInput;
  this->zAxis = zA;
}