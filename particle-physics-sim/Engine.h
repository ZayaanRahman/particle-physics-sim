// created by Zayaan Rahman
// 6/16/2023
//
// sets simulation settings and particles involved, and updates simulation state
// assumes 60 fps for now

#ifndef PARTICLE_PHYS_SIMULATOR_ENGINE_H
#define PARTICLE_PHYS_SIMULATOR_ENGINE_H

#include "Particle.h"
#include "CollisionDetector.h"
#include "CollisionResolver.h"

#include <string>
#include <vector>

class Engine {

  protected:

    // input file name
    std::string file;

    // space dimensions
    size_t width;
    size_t height;

    // collision detector and resolver
    CollisionDetector detector;
    CollisionResolver resolver;

    // complete set of particles in the simulation
    std::vector<Particle> particles;

    // add function to update acc, vel, and pos after resolving collisions

  public:

    // default constructor and .txt file constructor
    Engine();
    Engine(std::string file);

    // load space dimensions, particles, detector, and resolver from txt file
    void loadSettings(std::string file);

    // update particle states by a frame (assumes 60 fps for now)
    void update();
};


#endif //PARTICLE_PHYS_SIMULATOR_ENGINE_H
