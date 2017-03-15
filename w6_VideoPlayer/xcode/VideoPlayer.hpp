//
//  VideoPlayer.hpp
//  VideoPlayer
//
//  Created by Danli Hu on 3/1/17.
//
//

#pragma once

#include "cinder/qtime/QuickTimeGl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Surface.h"

class VideoPlayer;

typedef std::shared_ptr<VideoPlayer> VideoPlayerRef;
typedef ci::signals::Signal<void()> VideoEndedSignal;

class VideoPlayer
{
public:
    static VideoPlayerRef create();
    void setPath();
    void loadVideo(std::string _videoPath);
    void update();
    void draw();
    void play();
    void stop();
    void setLoop(bool bIsLoop);
    void onVideoEnded();
    float getLength();
    float getCurrent();
    
    VideoEndedSignal& getVideoEndedSignal(){return mVideoEndedSignal;}
    
private:
    VideoPlayer();
    void setup();
    
    VideoEndedSignal        mVideoEndedSignal;
    
    ci::gl::TextureRef mFrameTexture;
    ci::qtime::MovieGlRef mMovie;
    ci::fs::path mMoviePath;
};