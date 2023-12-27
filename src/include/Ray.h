#include "Vec3.h"

class Ray{
    private:
        Vec3 ori {0, 0, 0};
        Vec3 dir {0, 0, 0};

    public:
        Ray(const Vec3 &ori, const Vec3 &dir);       
        Vec3 origin() const;
        Vec3 direction() const;
        Vec3 location(f32 t) const;
};
