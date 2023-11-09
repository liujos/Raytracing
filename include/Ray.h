#include "Vector3.h"

class Ray{
    private:
        Vector3 origin;
        Vector3 direction;

    public:
        Ray(Vector3 &origin, Vector3 &direction);       
        Vector3 origin();
        Vector3 direction();
        Vector3 location(f32 t);
};
