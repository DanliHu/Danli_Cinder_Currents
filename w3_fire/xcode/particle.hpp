//
//  particle.hpp
//  w3_fire
//
//  Created by Danli Hu on 2/15/17.
//
//

#pragma once

class Particle {
    
public:
    Particle();
    void setup(float _width, float _height);
    void update();
    void draw(float _b);
    void applyForce(glm::vec2 _force);
    void restart();
    float alpha;
    
private:
    glm::vec2 vel;
    glm::vec2 acc;
    glm::vec2 pos;
    float mFriction;
    
    float width,height;
    cinder::gl::TextureRef fire;
};
