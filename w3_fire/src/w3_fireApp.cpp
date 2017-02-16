#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "particleSystem.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class w3_fireApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    particleSystem mParticleSystem;
};

void w3_fireApp::setup()
{
//    gl::enableAlphaBlending();
    gl::enableAdditiveBlending();
    mParticleSystem.setup(getWindowWidth(),getWindowHeight());
}

void w3_fireApp::mouseDown( MouseEvent event )
{
}

void w3_fireApp::update()
{
    mParticleSystem.update();
}

void w3_fireApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mParticleSystem.draw();
}

CINDER_APP( w3_fireApp, RendererGl )
