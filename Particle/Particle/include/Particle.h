#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Vec3.h"
#include <cstring>

class Particle
{
public:
    Particle()=default;
    Particle(const Vec3 &_pos, const Vec3 &_dir, size_t _maxLife);
    ~Particle()=default;
    Particle(const Particle &)=default;
    Particle(Particle &&)=default;
    Particle & operator =(const Particle &)=default;
    Particle & operator =(Particle &&)=default;

    Vec3 getPosition() const;
    void setPosition(const Vec3 &pos);

    size_t getLife() const;
    void setLife(size_t _life);

    Vec3 getColor() const;
    void setColor(const Vec3 &color);

    Vec3 getDirection() const;
    void setDirection(const Vec3 &_dir);

    size_t getMaxLife() const;
    void setMaxLife(size_t _maxlife);

    void update();

    void render() const;
    void renderGL() const;

private:
    Vec3 m_position;
    Vec3 m_color = {0.3f, 0.3f, 0.3f};
    size_t m_life = 0;
    Vec3 m_dir;
    size_t m_maxlife = 0;

};

#endif
