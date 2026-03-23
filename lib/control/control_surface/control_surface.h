#pragma once

enum ControlSurfaces
{
  AILERON_LEFT = 0,
  AILERON_RIGHT,
  ELEVATOR_LEFT,
  ELEVATOR_RIGHT,
  num_surface
};

struct ControlSurface
{
  //Servo servo;
  int GPIO_PIN;
  float angleZeroDegrees;
  float angleTrimOffsetDegrees;
  float angleServoMinDegrees;
  float angleServoMaxDegrees;
  const int DIRECTION_MULTIPLIER; // +1 or -1 to correct for rotational symmetry
  void init();
  void test();
  void move(float angle);
  void trim(float angle);
};
void MoveSurfaces(float jR, float jP);

extern ControlSurface surfaces[num_surface];

void SetBankAngle(float angle);
void SetPitchAngle(float angle);

void TestSurfaces();