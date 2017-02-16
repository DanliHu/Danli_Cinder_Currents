#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class w1_analogMeterApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void mouseDrag( MouseEvent event ) override;
    
    vec2 mousePos;
    float mouseX;
    float angle;
};

void w1_analogMeterApp::setup()
{
}

void w1_analogMeterApp::mouseDown( MouseEvent event )
{
}

void w1_analogMeterApp::mouseDrag( MouseEvent event )
{
    mousePos = event.getPos();
    mouseX = mousePos.x;
    float width = ci::app::getWindowSize().x;
    angle = lmap(mouseX, 0.f, width, 0.f, 2.5f);
}

void w1_analogMeterApp::update()
{
}

void w1_analogMeterApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    ci::vec2 center = 0.5f * ci::vec2(ci::app::getWindowSize());
    gl::pushModelView();
    gl::translate(center.x, center.y + 100);
    gl::rotate(glm::radians(-75.f));
    
    gl::pushModelView();
    gl::color(ci::Color(1.f,0.f,0.f));
    gl::rotate(angle);
    gl::drawSolidRect(Rectf(-1,0,1,-110));
    gl::popModelView();
    
    gl::color(ci::Color(1.f,1.f,1.f));
    
    for (int h=0; h<31; h++) {
        gl::pushModelView();
        gl::rotate(h* glm::radians(5.f));
        gl::drawSolidRect(Rectf(-1,-125,1,-110)); //top-left, bottom-right
        gl::popModelView();
    }
    
    for (int i=0; i<7; i++) {
        gl::pushModelView();
        gl::rotate(i* glm::radians(25.f));
        gl::drawSolidRect(Rectf(-1,-140,1,-110)); //top-left, bottom-right
        gl::popModelView();
    }
    gl::popModelView();
}

CINDER_APP( w1_analogMeterApp, RendererGl )
