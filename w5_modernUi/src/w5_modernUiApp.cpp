#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Timeline.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class w5_modernUiApp : public App {
  public:
	void setup() override;
    void mouseMove( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    Anim<float>oneFactor = 1.f;
    Anim<float>twoPosMove;
    
    vec2 onePos, twoPos, threePos;
    int space = 200;
    int size = 20;
    vec2 mousePos;
    bool mouseInOne, mouseInTwo, mouseInThree;
};

void w5_modernUiApp::setup()
{
    mouseInTwo = false;
    mouseInTwo = false;
    mouseInThree = false;

    onePos = vec2((getWindowWidth()/2)-space, (getWindowHeight()/2));
    twoPos = vec2((getWindowWidth()/2), (getWindowHeight()/2));
    threePos = vec2((getWindowWidth()/2)+space, (getWindowHeight()/2));
}

void w5_modernUiApp::mouseMove( MouseEvent event )
{
    mousePos = event.getPos();
}

void w5_modernUiApp::update()
{
    float distOne = sqrt(((mousePos.x - onePos.x)*(mousePos.x - onePos.x))+((mousePos.y - onePos.y)*(mousePos.y - onePos.y)));
    float distTwo = sqrt(((mousePos.x - twoPos.x)*(mousePos.x - twoPos.x))+((mousePos.y - twoPos.y)*(mousePos.y - twoPos.y)));
    float distThree = sqrt(((mousePos.x - threePos.x)*(mousePos.x - threePos.x))+((mousePos.y - threePos.y)*(mousePos.y - threePos.y)));
    
    if(distOne <= size){
        mouseInOne = true;
    }else{
        mouseInOne = false;
    }
    
    if(distTwo <= size){
        mouseInTwo = true;
    }else{
        mouseInTwo = false;
    }
    
    if(distThree <= size){
        mouseInThree = true;
    }else{
        mouseInThree = false;
    }
    
    if (mouseInOne) {
        timeline().apply(&oneFactor, 1.f,3.f,0.5f);
    }
    
    if (mouseInTwo) {
        timeline().apply(&twoPosMove,0.f,randFloat(-200,200),2.f);
        twoPos = vec2(twoPos.x, twoPos.y+twoPosMove);
        if(twoPos.y < space){
            twoPos.y = space;
        }
        if (twoPos.y > getWindowHeight()-space) {
            twoPos.y = getWindowHeight()-space;
        }
    }
}

void w5_modernUiApp::draw()
{
	gl::clear( Color( 0.85f, 0.85f, 0.85f ) );
    
    gl::color(0.3f, 0.3f, 0.3f);
    gl::drawSolidCircle(onePos, size*oneFactor);
    cout << oneFactor << endl;
    
    gl::color(1.f, 1.f, 1.f);
    gl::drawSolidCircle(twoPos, size);

    gl::color(0.5f, 0.5f, 0.5f);
    gl::drawSolidCircle(threePos, size);
}

CINDER_APP( w5_modernUiApp, RendererGl )
