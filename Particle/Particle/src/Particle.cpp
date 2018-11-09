#include "Particle.h"
#include <iostream>

Particle::Particle(const Vec3 &_pos,
                   const Vec3 &_dir,
                   size_t _maxLife):
    m_position(_pos), m_dir(_dir), m_maxlife(_maxLife)
{

}

Vec3 Particle::getPosition() const
{
    return m_position;
}

void Particle::setPosition(const Vec3 &pos)
{
    m_position = pos;
}

size_t Particle::getLife() const
{
    return m_life;
}

void Particle::setLife(size_t _life)
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

void Particle::setMaxLife(size_t _maxlife)
{
    m_maxlife = _maxlife;
}

size_t Particle::getMaxLife() const
{
    return m_maxlife;
}

void Particle::update()
{
    m_position += m_dir;
    m_life++;
    if (m_life >= m_maxlife)
    {
        // reset
        m_position = Vec3(0.0f, 0.0f, 0.0f);
        m_life = 0;
    }
}

void Particle::render() const
{
    std::cout << m_position.x << " " << m_position.y << " " << m_position.z << "\n";
}
