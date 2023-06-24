// created by Zayaan Rahman
// 6/7/2023
//
// Detects particle-particle and particle-boundary collisions

#ifndef PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H
#define PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H

#include "Particle.h"

#include <vector>
#include <utility>

class CollisionDetector {

  private:

    // space dimensions
    size_t width;
    size_t height;

    // Reference to vector particles in engine
    std::vector<Particle>& particlesRef;

  public:

    // default constructor and constructor using engine settings
    CollisionDetector();
    CollisionDetector(std::vector<Particle> particles, size_t width, size_t height);

    // detect particle-particle collisions, returning a vector of pairs of particles
    std::vector<std::pair<Particle, Particle>> DetectParticleCol();

    // detect particle-boundary collisions, returning a vector of pairs of particles and size_ts
    // a size_t number is used to reference each boundary
    std::vector<std::pair<Particle, size_t>> DetectBoundaryCol();


};


#endif //PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H
