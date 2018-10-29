#ifndef VEC3_H_
#define VEC3_H_

struct Vec3
{
    Vec3(float _x, float _y, float _z) : x(_x), y(_y),z(_z){}
    Vec3()=default;

    float x=0.0f;
    float y=0.0f;
    float z=0.0f;
};

#endif
