# This CMake file was used with the GCC 7.3.0 MinGW (DW2) - 32-bit download of SFML.
# Follow the official SFML instructions and tutorials for your operating system and environment.
# https://www.sfml-dev.org/download.php

cmake_minimum_required(VERSION 3.24)
project(particle_phys_simulator)

set(CMAKE_CXX_STANDARD 17)

# set SFML_DIR to the ..lib/cmake/SFML directory of the SFML library
set(SFML_DIR ".../SFML-2.5.1/lib/cmake/SFML") # will not build, add directory

# find the SFML modules used by the simulator
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# set source files
set(SOURCE_FILES
        main.cpp
        Particle.h
        Particle.cpp
        Engine.h
        Engine.cpp
        Visualizer.h
        Visualizer.cpp
        CollisionDetector.h
        CollisionDetector.cpp
        CollisionResolver.h
        CollisionResolver.cpp)

# add the source files to the executable
add_executable(particle_phys_simulator ${SOURCE_FILES})

# link the SFML library modules dynamically to the executable
target_link_libraries(particle_phys_simulator sfml-graphics sfml-window sfml-system)

# IMPORTANT: Copy the necessary dynamic library files from the .bin folder of SFML
#            and paste them into the directory of your executable. They must be in
#            the executable's directory at runtime.

# If using a different download of SFML or if building from source, you can also
# link the library statically.
