#include "Vector3.h"

Vector3::Vector3(f32 x, f32 y, f32 z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

f32 Vector3::x()
{
    return v[0];
}

f32 Vector3::y()
{
    return v[1];
}

f32 Vector3::z()
{
    return v[2];
}

Vector3 operator+(Vector3 &a, Vector3 &b)
{
    return Vector3(a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2]);
}

Vector3 operator*(Vector3 &a, Vector)
