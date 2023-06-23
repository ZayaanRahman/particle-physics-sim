// created by Zayaan Rahman
// 6/7/2023
//
// represents individual particle in simulation

#ifndef PARTICLE_PHYS_SIMULATOR_PARTICLE_H
#define PARTICLE_PHYS_SIMULATOR_PARTICLE_H

#include <cstddef>

class Particle {

  public:

    // unique identifier, useful if particle needs to be hashed or for particle tracking
    size_t id;

    double radius;

    // position
    double xpos;
    double ypos;

    // velocity
    double xvel;
    double yvel;

    // acceleration
    double xacc;
    double yacc;

    // default constructor
    Particle();
};


#endif //PARTICLE_PHYS_SIMULATOR_PARTICLE_H
