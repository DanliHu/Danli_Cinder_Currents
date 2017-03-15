//
//  VpInterface.cpp
//  w6_VideoPlayer
//
//  Created by Danli Hu on 3/8/17.
//
//

#include "VpInterface.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

void VpInterface::setup(){
    playPos = vec2(getWindowCenter());
    pausePos = vec2(getWindowWidth()/2 , getWindowHeight() - 25 );
    seekPos = vec2(getWindowWidth()/2 , getWindowHeight() - 50 );
    isPlay = false;
    size1 = 30;
    size2 = 30;
    seekWidth = getWindowWidth() - 100.f;
    seekHeight = 5;
}

void VpInterface::update(){

}

void VpInterface::draw(float videoLength, float currentLength){
    if (!isPlay) {
        playButton();
    }else{
        pauseButton();
    }
    seekbar(videoLength, currentLength);
}

void VpInterface::playButton(){
    gl::color(0.f,0.f,0.f,0.8f);
    gl::drawSolidCircle(playPos, 60);
    gl::color(1.f,1.f,1.f);
    vec2 offSet = vec2(playPos.x+8,playPos.y);
    gl::drawSolidTriangle(vec2(offSet.x-size1,offSet.y-size1), vec2(offSet.x-size1,offSet.y+size1), vec2(offSet.x+size1,offSet.y));
}

void VpInterface::pauseButton(){
    gl::color(1.f,1.f,1.f);
//    gl::drawSolidRect(Rectf(pausePos.x - size/2, pausePos.y - size/2, pausePos.x + size, pausePos.y + size));
    gl::drawSolidRect(Rectf(pausePos.x -   size2/2, pausePos.y -   size2/2, pausePos.x -   size2/6, pausePos.y +   size2/2));
        gl::drawSolidRect(Rectf(pausePos.x +   size2/6, pausePos.y -   size2/2, pausePos.x +   size2/2, pausePos.y +   size2/2));
}

void VpInterface::seekbar(float videoLength, float currentLength){
    gl::color(0.2f,0.2f,0.2f);
    vec2 start = vec2(seekPos.x - seekWidth/2, seekPos.y - seekHeight/2);
    vec2 end = vec2(seekPos.x + seekWidth/2, seekPos.y + seekHeight/2);
    gl::drawSolidRect(Rectf(start,end));
    int current = (int)lmap(currentLength, 0.f, videoLength, 50.f, seekWidth+50.f);
    vec2 middle = vec2(current, seekPos.y + seekHeight/2);
    gl::color(1.f,1.f,1.f);
    gl::drawSolidRect(Rectf(start,middle));
    
}