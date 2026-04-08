#pragma once
#include <cmath>

struct Vector3
{
public:
  Vector3();
  Vector3(float x, float y, float z);
  float x;
  float y;
  float z;
};

struct VectorTimestamped : Vector3
{
public:
  VectorTimestamped();
  VectorTimestamped(Vector3 &v, float t);
  VectorTimestamped(float x, float y, float z, float t);
  float time;
};

Vector3 operator+(const Vector3 &a, const Vector3 &b); // Evaluate a+b
Vector3 operator-(const Vector3 &a, const Vector3 &b); // Evaluate a-b
float operator*(const Vector3 &a, const Vector3 &b);   // Dot product
Vector3 operator*(const Vector3 &v,
                  float scalar); // Scalar multiplication (vector, scalar)
Vector3 operator*(float scalar,
                  const Vector3 &v);               // Scalar multiplication (scalar, vector)
Vector3 cross(const Vector3 &a, const Vector3 &b); // Cross product
Vector3 unit(const Vector3 &
                 v); // Unit vector of v. If ||v|| == 0, returns the zero vector

struct Quaternion
{ // Look, I know a quaternion is technically not exactly a vector, but I don't care
public:
  Quaternion();
  Quaternion(float w, float i, float j, float k);
  float w;
  float i;
  float j;
  float k;
};
