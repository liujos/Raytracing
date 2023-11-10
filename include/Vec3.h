#pragma once
#include "basic.h"

struct Vec3 {
        f32 x, y, z;
        Vec3(f32 x, f32 y, f32 z);
        f32 length() const;
};

Vec3 operator+(const Vec3 &a, const Vec3 &b);

Vec3 operator*(const Vec3 &v, const f32 t);
Vec3 operator*(const f32 t, const Vec3 &v);

Vec3 operator/(const Vec3 &v, const f32 t);

Vec3 operator-(const Vec3 &a, const Vec3 &b);

f32 dot(const Vec3 &a, const Vec3 &b);
Vec3 normalize(const Vec3 &v);

std::ostream& operator<<(std::ostream &out, const Vec3 &v);


