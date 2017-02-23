#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Fireworks.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class w4_fireworksApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
//    vector<Fireworks> mFireworks;
    std::vector<FireworkRef> mFireworks;
};

void w4_fireworksApp::setup()
{
}

void w4_fireworksApp::mouseDown( MouseEvent event )
{
//    Fireworks temp;
//    temp.setup(event.getPos());
//    mFireworks.push_back(temp);
    
    mFireworks.push_back(Fireworks::create(event.getPos()));
}

void w4_fireworksApp::update()
{
    
    for (auto& p: mFireworks){
        p->update();
    }
    
    // remove particle if it has passed its lifespan
    for (auto p = mFireworks.begin(); p != mFireworks.end();)
    {
        if ( (*p)->life() < 0) {
            mFireworks.erase(p);
        } else {
            ++p;
        }
        
    }
    
}

void w4_fireworksApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    gl::ScopedBlendAdditive blend;
    
    for (auto& p: mFireworks){
        p->draw();
    }
}

CINDER_APP( w4_fireworksApp, RendererGl )
