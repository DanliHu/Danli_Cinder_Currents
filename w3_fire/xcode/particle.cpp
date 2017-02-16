//
//  particle.cpp
//  w3_fire
//
//  Created by Danli Hu on 2/15/17.
//
//

#include "particle.hpp"
#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

Particle::Particle(){
}

void Particle::setup(float _width, float _height){
    width = _width;
    height = _height;
    pos.x = width/2 + ci::randFloat(-60.f,60.f);
    pos.y = height-100.f + ci::randFloat(-15.f,15.f);
    mFriction = 1.f;
    vel = glm::vec2(0.f,0.f);
    acc = glm::vec2(0.f,0.f);
    alpha = ci::randFloat(0.5,1.f);
    
    
    fire = cinder::gl::Texture::create(loadImage(cinder::app::loadAsset("fire.png")));
}

void Particle::update(){
    vel = vel + acc;
    vel *= mFriction;
    pos = pos + vel;
    
    acc *= 0.f;
    alpha -= 0.045f;
}

void Particle::draw(float _b){
//    ci::gl::pushModelView();
//    ci::gl::translate(pos);
//    cinder::gl::rotate(glm::radians(cinder::randFloat(0.f,360.f)));
    cinder::gl::color(ci::ColorA(1.f,_b,1.f,alpha));
    ci::gl::draw(fire,pos);
//    ci::gl::popModelView();
    
    cinder::gl::color(ci::ColorA(1.f,0.8f,0.f,alpha));
    ci::gl::drawSolidCircle(ci::vec2(pos.x+10,pos.y+35), 1.f);
}

void Particle::applyForce(glm::vec2 _force){
    acc += _force;
}

void Particle::restart(){
    pos.x = width/2 + ci::randFloat(-60.f,60.f);
    pos.y = height-100.f + ci::randFloat(-15.f,15.f);
    alpha = ci::randFloat(0.5,1.f);
    
    vel = glm::vec2(0.f,0.f);
    acc = glm::vec2(0.f,0.f);
}
