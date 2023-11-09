#pragma once
#include "basic.h"

struct Vector3 {
    f32 v[3];

    Vector3(f32 x, f32 y, f32 z);
    f32 x(); 
    f32 y(); 
    f32 z(); 
};
