// created by Zayaan Rahman
// 6/7/2023
//
// Detects particle-particle and particle-boundary collisions

#ifndef PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H
#define PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H

#include "Particle.h"

#include <vector>
#include <utility>
#include <cmath>

// TODO: Figure out if detector and resolver should use virtual functions for extensibiliy
// TODO: figure out if reference variables will work, or if pointers needed

class CollisionDetector {

  public:

    // constructor using engine settings
    CollisionDetector(size_t width, size_t height, std::vector<Particle>& particles);

    // detect particle-particle collisions, returning a vector of pairs of nums that refer to
    // the indices of colliding particles
    std::vector<std::pair<size_t, size_t>> DetectPPCollision();

    // detect particle-boundary collisions, returning a vector of pairs of size_ts; the first num refers
    // to the index of a particle, and the second num is the index of the boundary it collides with:
    // 1,2,3,4 correspond to top, right, bottom, left respectively TENTATIVELY
    std::vector<std::pair<size_t, size_t>> DetectPBCollision();

  private:
    // space dimensions

    size_t width;
    size_t height;

    // reference to vector particles in engine
    std::vector<Particle>& particlesRef;


    // returns true if two particles intersect
    bool intersect(Particle& p1, Particle& p2);

    // returns true if a particle and boundary intersect
    bool intersect(Particle& p1, size_t boundary);

};


#endif //PARTICLE_PHYS_SIMULATOR_COLLISIONDETECTOR_H
