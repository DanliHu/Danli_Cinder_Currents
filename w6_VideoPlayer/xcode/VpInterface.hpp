//
//  VpInterface.hpp
//  w6_VideoPlayer
//
//  Created by Danli Hu on 3/8/17.
//
//

#pragma once

using namespace ci;
using namespace ci::app;
using namespace std;

class VpInterface{
public:
    void setup();
    void update();
    void draw(float videoLength, float currentLength);
    
    void playButton();
    void pauseButton();
    void seekbar(float videoLength, float currentLength);
    
    bool isPlay;

private:
    vec2 playPos, pausePos, seekPos;
    int size1, size2, seekHeight;
    float seekWidth;
};