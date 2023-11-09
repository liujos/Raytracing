#include "Ray.h"

Ray::Ray(Vector3 &origin, Vector3 &direction)
{
    this->origin = origin;
    this->direction = direction;
}

Vector3 Ray::origin()
{
    return origin;
}

Vector3 Ray::direction()
{
    return direction;
}

Vector3 Ray::location(f32 t)
{
    return origin + t * direction;
}

