//
//  Fireworks.hpp
//  w4_fireworks
//
//  Created by Danli Hu on 2/22/17.
//
//

#pragma once
#include "Particle.hpp"

class Fireworks;
typedef std::shared_ptr<Fireworks> FireworkRef;

class Fireworks {
    
public:
    static FireworkRef create(glm::vec2 pos);

    void setup(glm::vec2 pos);
    void update();
    void draw();
    int life(){return fireworkLife;}
    
    const int	NUM_PARTICLES = 200;
    const float  RANDOM_RANGE = 10.f;
    const float  RANDOM_FORCE_RANGE = 2.f;
    const float LIFE_SPAN = 3.f;
    
    std::vector<ParticleRef> mParticles;
    float                    mTime;
    int fireworkLife;
    
private:
    Fireworks();
};