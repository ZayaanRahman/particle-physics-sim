// created by Zayaan Rahman
// 6/7/2023
//
// Detects particle-particle and particle-boundary collisions

#ifndef PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H
#define PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H

#include "Particle.h"

#include <vector>

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

    // detect particle-particle collisions and particle-boundary collisions



};


#endif //PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H
