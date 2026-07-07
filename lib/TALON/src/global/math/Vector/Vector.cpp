#include "global/math/Vector/Vector.h"
#include <math.h>

Vector3 operator+(const Vector3 &a, const Vector3 &b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }

Vector3 operator-(const Vector3 &a, const Vector3 &b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }

float operator*(const Vector3 &a, const Vector3 &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Vector3 operator*(const Vector3 &v, float scalar) { return {v.x * scalar, v.y * scalar, v.z * scalar}; }

Vector3 operator*(float scalar, const Vector3 &v) { return v * scalar; }

Vector3 cross(const Vector3 &a, const Vector3 &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

float normalize360(float a) {
    while (a < 0)
        a += 360;
    while (a >= 360)
        a -= 360;
    return a;
}

Vector3 unit(const Vector3 &v) {
    float magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (magnitude == 0)
        return {0, 0, 0};
    return {v.x / magnitude, v.y / magnitude, v.z / magnitude};
}

float Vector3::magnitude() { return sqrt(x * x + y * y + z * z); }
float Vector3::lengthXY() { return sqrt(x * x + y * y); }

float radToDeg(float r) { return r * 180 / M_PI; }

float headingDegreesXY(const Vector3 &v) { return normalize360(radToDeg(atan2(v.x, v.y))); }

Quaternion::Quaternion() {
    this->w = 1;
    this->i = 0;
    this->j = 0;
    this->k = 0;
}

Quaternion::Quaternion(float w, float i, float j, float k) {
    this->w = w;
    this->i = i;
    this->j = j;
    this->k = k;
}