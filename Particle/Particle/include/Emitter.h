#ifndef EMITTER_H
#define EMIITER_H
#include<cstring>
#include "Particle.h"
#include <vector>

class Emitter
{
public:
    Emitter()=default;
    Emitter(const Vec3 &_pos, size_t numParticles);
    Emitter(const Emitter &) = default;
    void render() const;
    void update();
    size_t getNumParticles() const;
private:
    size_t m_numParticles = 0;
    std::vector<Particle> m_particles;
    Vec3 m_pos;
};

#endif
