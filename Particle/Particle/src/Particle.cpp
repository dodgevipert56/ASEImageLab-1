#include "Particle.h"
#include <iostream>

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

void Particle::setDirection(const Vec3 &_dir)
{
    m_dir = _dir;
}

Vec3 Particle::getDirection() const
{
    return m_dir;
}

void Particle::setMaxLife(int _maxlife)
{
    m_maxlife = _maxlife;
}

int Particle::getMaxLife() const
{
    return m_maxlife;
}

void Particle::update()
{
    m_position += m_dir;
}

void Particle::render() const
{
    std::cout << m_position.x << " " << m_position.y << " " << m_position.z << "\n";
}
