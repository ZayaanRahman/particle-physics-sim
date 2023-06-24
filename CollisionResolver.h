// created by Zayaan Rahman
// 6/7/2023
//
// Resolves particle-particle and particle-boundary collisions

#ifndef PARTICLE_PHYS_SIMULATOR_COLLISIONRESOLVER_H
#define PARTICLE_PHYS_SIMULATOR_COLLISIONRESOLVER_H

#include "Particle.h"

#include <vector>
#include <utility>

class CollisionResolver {

  private:

    // space dimensions
    size_t width;
    size_t height;

    // Reference to vector particles in engine
    std::vector<Particle>& particlesRef;

  public:

    // default constructor and constructor using engine settings
    CollisionResolver();
    CollisionResolver(std::vector<Particle> particles, size_t width, size_t height);

    // resolve particle-particle collisions
    void resolveParticleCol(std::vector<std::pair<Particle, Particle>> particleCollisions);

    // resolve particle-boundary collisions
    void resolveBoundaryCol(std::vector<std::pair<Particle, size_t>> boundaryCollisions);


};


#endif //PARTICLE_PHYS_SIMULATOR_COLLISIONRESOLVER_H
