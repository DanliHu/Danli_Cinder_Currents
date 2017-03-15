#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "VideoPlayer.hpp"
#include "VpInterface.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class w6_VideoPlayerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void onVideoEnded();
    
    bool videoEnded;
    
    VideoPlayerRef mVideo;
    VpInterface mInterface;
};

void w6_VideoPlayerApp::setup()
{
    mVideo = VideoPlayer::create();
    mVideo -> setPath();
    mVideo -> loadVideo("EccoCoolMen.mp4");
    mInterface.setup();
    mVideo->getVideoEndedSignal().connect(std::bind(&w6_VideoPlayerApp::onVideoEnded, this));
    
    videoEnded = false;
}

void w6_VideoPlayerApp::mouseDown( MouseEvent event )
{
    mInterface.isPlay = !mInterface.isPlay;
}

void w6_VideoPlayerApp::onVideoEnded(){
    cout << "aaaaaaaaa" << endl;
    videoEnded = true;
}

void w6_VideoPlayerApp::update()
{
    mVideo -> update();
    if (mInterface.isPlay) {
        mVideo -> play();
    }else{
        mVideo -> stop();
    }
}

void w6_VideoPlayerApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    gl::color(1.f, 1.f, 1.f);
    mVideo -> draw();
    mInterface.draw(mVideo->getLength(),mVideo->getCurrent());
    
    if (videoEnded) {
        gl::drawSolidCircle(getWindowCenter(), 100);
    }
}

CINDER_APP( w6_VideoPlayerApp, RendererGl )
