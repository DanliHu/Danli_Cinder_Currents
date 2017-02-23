//
//  Particle.cpp
//  w4_fireworks
//
//  Created by Danli Hu on 2/22/17.
//
//

#include "Particle.hpp"
#include "cinder/Rand.h"

ParticleRef Particle::create(glm::vec2 position, float lifespa){
    ParticleRef ref = std::shared_ptr<Particle>(new Particle());
    ref -> setup(position, lifespa);
    return ref;
}

Particle::Particle()
:mFriction(0.98)
//,mVelocity(glm::vec2(ci::randFloat(-2.f,2.f),ci::randFloat(-2.f,2.f)))
,mVelocity(glm::vec2(0.f,0.f))
,mAcceleration(glm::vec2(0.f,ci::randFloat(0.01f,0.02f)))
{
    
}

float Particle::getTimerleft(){
    return (mLifespan - mTimer.getSeconds());
}

void Particle::setup(glm::vec2 position, float lifespan){
    mLifespan = lifespan;
    mPosition = position;
    prePosition = mPosition;
    alpha = 1.f;
    mTimer.start();
}

void Particle::update(){
    
    if(rand() % 5 == 0){
    prePosition = mPosition;
    }
    
    mVelocity *= mFriction;
    mPosition += mVelocity;
    mVelocity += mAcceleration;
    
    alpha -= 0.005;
}

void Particle::draw(){
    float r = getTimerleft()/getLifespan();
    ci::gl::color(r,0.3,1.f-r,alpha);
    ci::gl::drawSolidCircle(mPosition, 1);
}

void Particle::applyForce(glm::vec2 force){
    mVelocity += force;
}