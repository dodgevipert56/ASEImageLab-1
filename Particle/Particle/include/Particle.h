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

    Vec3 getColor() const;
    void setColor(const Vec3 &color);

    Vec3 getDirection() const;
    void setDirection(const Vec3 &dir);

    int getLifeTime() const;
    void setLifeTime(int _lifetime);

private:
    Vec3 m_position;
    Vec3 m_color = {0.0f, 0.0f, 0.0f};
    int m_life = 0;
    Vec3 m_dir;
    int m_lifetime = 0;

};

#endif
