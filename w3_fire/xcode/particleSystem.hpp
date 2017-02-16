//
//  particleSystem.hpp
//  w3_fire
//
//  Created by Danli Hu on 2/15/17.
//
//

#pragma once
#include "particle.hpp"

class particleSystem {
    
public:
    particleSystem();
    
    void setup(float _width, float _height);
    void update();
    void draw();

    int num;
    int frame;
    std::vector<Particle> mParticles;
};
