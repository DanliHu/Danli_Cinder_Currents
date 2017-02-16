//
//  particleSystem.cpp
//  w3_fire
//
//  Created by Danli Hu on 2/15/17.
//
//

#include "particleSystem.hpp"
#include "cinder/Rand.h"

particleSystem::particleSystem(){

}

void particleSystem::setup(float _width, float _height){
    num = 400;
    frame = 0;
    for (int i=0; i<num; i++) {
        Particle tempP;
        tempP.setup(_width,_height);
        mParticles.push_back(tempP);
    }
}

void particleSystem::update(){
    frame++;
    
    for (int i=0; i<mParticles.size(); i++) {
        mParticles[i].update();
        
//        float x = ci::randFloat(-0.1,0.1);
        float y = ci::randFloat(0.f,-3.f);
        mParticles[i].applyForce(ci::vec2(0.f,y));
        
//        if (mParticles[i].alpha < 0) {
//            mParticles[i].restart();
//        }
        int randNum = ci::randInt(1,400);
        if(frame % randNum == 0){
            mParticles[i].restart();
        }
    }
    
    
}

void particleSystem::draw(){
    for (int i=0; i<mParticles.size(); i++) {
        float b = ci::randFloat(0.5,1.f);
        mParticles[i].draw(b);
    }
}