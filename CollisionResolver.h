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

    // reference to vector particles in engine
    std::vector<Particle>& particlesRef;

  public:

    // constructor using engine settings
    CollisionResolver(std::vector<Particle> particles, size_t width, size_t height);

    // resolve particle-particle collisions
    void resolveParticleCol(std::vector<std::pair<size_t, size_t>> particleCollisions);

    // resolve particle-boundary collisions
    void resolveBoundaryCol(std::vector<std::pair<size_t, size_t>> boundaryCollisions);


};


#endif //PARTICLE_PHYS_SIMULATOR_COLLISIONRESOLVER_H
