//
//  VideoPlayer.cpp
//  VideoPlayer
//
//  Created by Danli Hu on 3/1/17.
//
//

#include "VideoPlayer.hpp"

VideoPlayerRef VideoPlayer::create(){
    VideoPlayerRef ref = std::shared_ptr<VideoPlayer>(new VideoPlayer());
    ref -> setup();
    return ref;
}

VideoPlayer::VideoPlayer()
{
    
}

void VideoPlayer::setPath(){
//    try {
//        mMoviePath = ci::app::getAssetPath(videoPath);
//    } catch (std::exception& e) {
//        ci::app::console() << e.what() << std::endl;
//    }
    
    try {
        ci::fs::path p = cinder::app::getOpenFilePath("");
        std::string videoPath = p.string();
        if( ! videoPath.empty() ) { // an empty string means the user canceled
//            mMoviePath = ci::app::getAssetPath(p);
        }
    }
    
    catch(std::exception& e) {
        ci::app::console() << e.what() << std::endl;
    }
    
}

void VideoPlayer::loadVideo(std::string _videoPath){
    try {
        mMoviePath = ci::app::getAssetPath(_videoPath);
        mMovie = ci::qtime::MovieGl::create(mMoviePath);
//        mMovie -> setLoop();
//        mMovie -> play();
    } catch (std::exception& e) {
        ci::app::console() << e.what() << std::endl;
        mMovie.reset();
    }
}

void VideoPlayer::setup(){
}

void VideoPlayer::update(){
    if (mMovie) {
        mFrameTexture = mMovie -> getTexture();
    }
}

void VideoPlayer::play(){
    mMovie -> play();
}

void VideoPlayer::stop(){
    mMovie -> stop();
}

void VideoPlayer::setLoop(bool bIsLoop){
    if(mMovie){
        mMovie->setLoop(bIsLoop);
    }
}

void VideoPlayer::onVideoEnded(){
     mVideoEndedSignal.emit();
}

void VideoPlayer::draw(){
    if (mFrameTexture) {
        ci::Rectf centeredRect = ci::Rectf(mFrameTexture -> getBounds()).getCenteredFit(ci::app::getWindowBounds(), true);
        ci::gl::draw(mFrameTexture, centeredRect);

    }
}

float VideoPlayer::getLength(){
    float length = mMovie -> getDuration();
    return length;
}

float VideoPlayer::getCurrent(){
    float current = mMovie -> getCurrentTime();
    return current;
}