#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Vec3.h"

class Particle
{
public:
    Particle()=default;
    ~Particle()=default;
    Particle(const Particle &)=default;
    Particle(Particle &&)=default;
    Particle & operator =(const Particle &)=default;
    Particle & operator =(Particle &&)=default;

    Vec3 getPosition() const;
    void setPosition(const Vec3 &pos);
    int getLife() const;
    void setLife(int _life);
    void setColor(const Vec3 &color);
    Vec3 getColor() const;

private:
    Vec3 m_position; // already already defined as 0.0f, 0.0f, 0.0f; but may be declared to another
    Vec3 m_color = {0.0f, 0.0f, 0.0f};
    int m_life = 0;

};

#endif
