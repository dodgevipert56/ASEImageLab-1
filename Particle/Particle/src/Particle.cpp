#include "Particle.h"

Vec3 Particle::getPosition() const
{
    return m_position;
}

void Particle::setPosition(const Vec3 &pos)
{
    m_position = pos;
}

int Particle::getLife() const
{
    return m_life;
}

void Particle::setLife(int _life)
{
    m_life=_life;
}

void Particle::setColor(const Vec3 &color)
{
    m_color = color;
}

Vec3 Particle::getColor() const
{
    return m_color;
}

void Particle::setDirection(const Vec3 &dir)
{
    m_dir = dir;
}

Vec3 Particle::getDirection() const
{
    return m_dir;
}

void Particle::setLifeTime(int _lifetime)
{
    m_lifetime = _lifetime;
}

int Particle::getLifeTime() const
{
    return m_lifetime;
}
