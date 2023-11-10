#include "Ray.h"

Ray::Ray(const Vec3 &ori, const Vec3 &dir)
{
    this->ori = ori;
    this->dir = dir;
}

Vec3 Ray::origin() const
{
    return ori;
}

Vec3 Ray::direction() const
{
    return dir;
}

Vec3 Ray::location(f32 t) const
{
    return ori+ t * dir;
}

