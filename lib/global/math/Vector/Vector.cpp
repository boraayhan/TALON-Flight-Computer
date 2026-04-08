#include "global/math/Vector/Vector.h"

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

VectorTimestamped::VectorTimestamped()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->time = 0;
}

VectorTimestamped::VectorTimestamped(Vector3& v, float t)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->time = t;
}

VectorTimestamped::VectorTimestamped(float x, float y, float z, float t)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->time = t;
}

Vector3 operator+(const Vector3 &a, const Vector3 &b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector3 operator-(const Vector3 &a, const Vector3 &b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

float operator*(const Vector3 &a, const Vector3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 operator*(const Vector3 &v, float scalar)
{
    return {v.x * scalar, v.y * scalar, v.z * scalar};
}

Vector3 operator*(float scalar, const Vector3 &v) { return v * scalar; }

Vector3 cross(const Vector3 &a, const Vector3 &b)
{
    return {
        a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

Vector3 unit(const Vector3 &v)
{
    float magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (magnitude == 0)
        return {0, 0, 0};
    return {v.x / magnitude, v.y / magnitude, v.z / magnitude};
}

Quaternion::Quaternion()
{
    this->w = 1;
    this->i = 0;
    this->j = 0;
    this->k = 0;
}

Quaternion::Quaternion(float w, float i, float j, float k)
{
    this->w = w;
    this->i = i;
    this->j = j;
    this->k = k;
}