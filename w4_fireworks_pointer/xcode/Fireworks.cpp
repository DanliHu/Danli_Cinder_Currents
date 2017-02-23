//
//  Fireworks.cpp
//  w4_fireworks
//
//  Created by Danli Hu on 2/22/17.
//
//

#include "Fireworks.hpp"
#include "cinder/Rand.h"

using namespace ci;

FireworkRef Fireworks::create(glm::vec2 pos){
    FireworkRef ref = std::shared_ptr<Fireworks>(new Fireworks());
    ref -> setup(pos);
    return ref;
}

Fireworks::Fireworks(){
}

void Fireworks::setup(glm::vec2 pos){
    for (int i=0; i<NUM_PARTICLES; i++) {
        mParticles.push_back(Particle::create(pos, LIFE_SPAN));
    }
    
    for (auto& p: mParticles){
        
        gl::pushMatrices();
        gl::translate(p->getPosition());
        
        float r = randFloat(0.f,100.f);
        float angle = randFloat(0.f,360.f);
        float x = r * cos(angle);
        float y = r * sin(angle);
        glm::vec2 force = glm::vec2(x,y);
        force = normalize(force) * randFloat(0.f,2.f);
        
        p->applyForce(force);
        
        gl::popMatrices();
        
    }
    
    fireworkLife = 200;
}


void Fireworks::update(){
    mTime = ci::app::getElapsedSeconds() * 100.f;
    
    for (auto& p: mParticles){
        p->update();
    }
    
    for (auto p = mParticles.begin(); p != mParticles.end();)
    {
        if ( (*p)->getTimerleft() < 0) {
            p = mParticles.erase(p);
        } else {
            ++p;
        }
        
    }
    fireworkLife --;
}

void Fireworks::draw(){
    gl::begin(GL_LINES);
    
    for (auto& p: mParticles){
        gl::vertex(p->getPosition());
        gl::vertex(p->getPrepos());
        p->draw();
    }
    
    gl::end();
}