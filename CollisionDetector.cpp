// created by Zayaan Rahman
// 6/16/2023
//
// Detects particle-particle and particle-boundary collisions

#include "CollisionDetector.h"


// constructor using engine settings
CollisionDetector::CollisionDetector(size_t width, size_t height, std::vector<Particle>& particles):
width(width), height(height), particlesRef(particles) {}

// detect particle-particle collisions, returning a vector of pairs of nums that refer to
// the indices of colliding particles
std::vector<std::pair<size_t, size_t>> CollisionDetector::DetectPPCollision()
{
    std::vector<std::pair<size_t, size_t>> collisions;

    // iterate through the vector of particles
    for (size_t i = 0; i < particlesRef.size(); i++) {

        // for each particle, iterate through the particles after it
        for (size_t j = i + 1; j < particlesRef.size(); j++) {

            // if particles at i and j intersect, add the pair to collisions
            if (intersect(particlesRef[i], particlesRef[j])) {

                collisions.emplace_back(i, j);
            }
        }
    }

    return collisions;
}

// detect particle-boundary collisions, returning a vector of pairs of size_ts; the first num refers
// to the index of a particle, and the second num is the index of the boundary it collides with:
// 1,2,3,4 correspond to top, right, bottom, left respectively TENTATIVELY
std::vector<std::pair<size_t, size_t>> CollisionDetector::DetectPBCollision()
{
    std::vector<std::pair<size_t, size_t>> collisions;

    // iterate through the vector of particles
    for (size_t i = 0; i < particlesRef.size(); i++) {

        // for each particle, check if it intersects with each of the 4 boundaries
        for (size_t j = 1; j <= 4; j++) {

            // if particles at i intersects a boundary, add the pair to collisions
            if (intersect(particlesRef[i], j)) {

                collisions.emplace_back(i, j);
            }
        }
    }

    return collisions;
}


// returns true if two particles intersect
bool CollisionDetector::intersect(Particle& p1, Particle& p2)
{
    // compares the distance between the centers of the particles to the sum of their radii
    double distance = std::sqrt(std::pow(p2.xpos - p1.xpos, 2) +
                                   std::pow(p2.ypos - p1.ypos, 2));

    return distance <= p1.radius + p2.radius;
}

// returns true if a particle and boundary intersect
bool CollisionDetector::intersect(Particle& p1, size_t boundary)
{
    // compares boundary value to particle position, factoring in radius
    switch (boundary) {
        case 1:
            return p1.ypos + p1.radius >= height;
            break;
        case 2:
            return p1.xpos + p1.radius >= width;
            break;
        case 3:
            return p1.ypos - p1.radius <= 0;
            break;
        case 4:
            return p1.xpos - p1.radius <= 0;
            break;
        default:
            break;
    } // probably better to just use if then in collision detection function, replace later

}

