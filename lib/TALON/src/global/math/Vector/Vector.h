#pragma once
#include <math.h>

struct Vector3 {
  public:
    float x; // +X: East, -X: West when used to store position
    float y; // +Y: North, -Y: South when used to store position
    float z; // +Z: Increasing altitude, -Z: Decreasing altitude. Z = 0 is "ground level + landing gear" height.
    float magnitude();
};

Vector3 operator+(const Vector3 &a, const Vector3 &b); // Evaluate a+b
Vector3 operator-(const Vector3 &a, const Vector3 &b); // Evaluate a-b
float operator*(const Vector3 &a, const Vector3 &b);   // Dot product
Vector3 operator*(const Vector3 &v, float scalar);     // Scalar multiplication (vector, scalar)
Vector3 operator*(float scalar, const Vector3 &v);     // Scalar multiplication (scalar, vector)
Vector3 cross(const Vector3 &a, const Vector3 &b);     // Cross product
Vector3 unit(const Vector3 &v);                        // Unit vector of v. If ||v|| == 0, returns the zero vector
Vector3 dist(const Vector3 &a, const Vector3 &b);      // Find distance between two vectors
float normalize360(float a);                           // Convert DEG angle (a) to principal angle (b), 0 <= b < 360
float radToDeg(float r);                               // Compute degrees angle of given radians angle
float headingDegreesXY(const Vector3 &v);              // Modification of atan2() to use +Y axis as 0 degrees

struct Quaternion { // Look, I know a quaternion is technically not exactly a vector, but I don't care
  public:
    Quaternion();
    Quaternion(float w, float i, float j, float k);
    float w;
    float i;
    float j;
    float k;
};
