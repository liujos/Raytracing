#include "Vec3.h"

Vec3::Vec3(f32 _x, f32 _y, f32 _z)
{
    x = _x;
    y = _y;
    z = _z;
}

f32 Vec3::length() const
{
    return sqrt(x * x + y * y + z * z);
}

Vec3 normalize(const Vec3 &v) 
{
    return v / v.length();
}

f32 dot(const Vec3 &a, const Vec3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 operator+(const Vec3 &a, const Vec3 &b)
{
    return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 operator*(const Vec3 &v, const f32 t)
{
    return Vec3(t * v.x, t * v.y, t * v.z);
}

Vec3 operator*(const f32 t, const Vec3 &v)
{
    return v * t;
}

Vec3 operator/(const Vec3 &v, const f32 t)
{
    return Vec3(v.x / t, v.y / t, v.z / t);
}

Vec3 operator-(const Vec3 &a, const Vec3 &b)
{
    return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

std::ostream& operator<<(std::ostream &out, const Vec3 &v)
{
    return out << v.x << " " << v.y << " " << v.z;
}

