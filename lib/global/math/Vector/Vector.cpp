#include "global/math/Vector/Vector.h"

Vector3 operator+(const Vector3 &a, const Vector3 &b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }

Vector3 operator-(const Vector3 &a, const Vector3 &b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }

double operator*(const Vector3 &a, const Vector3 &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Vector3 operator*(const Vector3 &v, double scalar) {
    return {v.x * scalar, v.y * scalar, v.z * scalar};
}

Vector3 operator*(double scalar, const Vector3 &v) { return v * scalar; }

Vector3 cross(const Vector3 &a, const Vector3 &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

Vector3 unit(const Vector3 &v) {
    double magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (magnitude == 0)
        return {0, 0, 0};
    return {v.x / magnitude, v.y / magnitude, v.z / magnitude};
}