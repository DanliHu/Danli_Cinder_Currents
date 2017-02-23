//
//  Particle.hpp
//  w4_fireworks
//
//  Created by Danli Hu on 2/22/17.
//
//

#pragma once
#include <memory>

class Particle;

typedef std::shared_ptr<Particle> ParticleRef;

class Particle{
public:
    static ParticleRef create(glm::vec2 position, float lifespan);
    glm::vec2 getPosition(){return mPosition;}
    glm::vec2 getPrepos(){return prePosition;}
    
    float getTimerleft();
    float getLifespan(){return mLifespan;};
    void update();
    void draw();
    void applyForce(glm::vec2 force);
    
private:
    Particle();
    void setup(glm::vec2 position, float lifespan);
    
    glm::vec2 mPosition;
    glm::vec2 prePosition;
    
    float mFriction;
    float mLifespan;
    glm::vec2 mVelocity;
    glm::vec2 mAcceleration;
    float alpha;
    
    ci::Timer mTimer;
};