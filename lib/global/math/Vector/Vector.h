#pragma once
#include <cmath>

struct Vector3 {
    double x;
    double y;
    double z;
};

Vector3 operator+(const Vector3 &a, const Vector3 &b); // Evaluate a+b
Vector3 operator-(const Vector3 &a, const Vector3 &b); // Evaluate a-b
double operator*(const Vector3 &a, const Vector3 &b);  // Dot product
Vector3 operator*(const Vector3 &v, double scalar);    // Scalar multiplication (vector, scalar)
Vector3 operator*(double scalar, const Vector3 &v);    // Scalar multiplication (scalar, vector)
Vector3 cross(const Vector3 &a, const Vector3 &b);     // Cross product
Vector3 unit(const Vector3 &v); // Unit vector of v. If ||v|| == 0, returns the zero vector