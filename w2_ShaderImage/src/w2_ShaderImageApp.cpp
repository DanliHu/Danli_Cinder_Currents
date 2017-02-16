#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class w2_ShaderImageApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void mouseMove( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    gl::TextureRef myTexture;
    gl::TextureRef myTextureDark;
    
//    ci::Surface8u mySurface;
//    gl::TextureRef myTexFromSurface;
    
    vec2 mousePos;
    
    gl::GlslProgRef     mShader;
};

void w2_ShaderImageApp::setup()
{
    ci::app::setWindowSize(1024,768);
    
    try {
        myTexture = gl::Texture::create(loadImage(loadAsset("pic.jpg")));
        myTextureDark = gl::Texture::create(loadImage(loadAsset("pic2.jpg")));
        
//        mySurface = loadImage(loadAsset("pic.jpg"));
        
        mShader = gl::GlslProg::create( loadAsset( "shader.vert" ), loadAsset( "shader.frag" ) );
        
    } catch (exception& e) {
        ci::app::console()<< e.what()<<std::endl; //cout
    }
}

void w2_ShaderImageApp::mouseDown( MouseEvent event )
{
}

void w2_ShaderImageApp::mouseMove( MouseEvent event )
{
    mousePos = event.getPos();
}

void w2_ShaderImageApp::update()
{
}

void w2_ShaderImageApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::ScopedGlslProg shader( mShader );
    
    mShader->uniform( "tex0", 0 );
    mShader->uniform( "tex1", 1 );
    mShader->uniform( "u_mouse", mousePos);
    mShader->uniform("u_resolution", vec2(getWindowWidth(), getWindowHeight()));
    
    gl::draw(myTexture,Rectf(0.f,0.f,getWindowSize().x,getWindowSize().y));
//    myTexFromSurface = gl::Texture::create(mySurface);
    
    gl::ScopedTextureBind tex0( myTexture, (uint8_t)0 );
    gl::ScopedTextureBind tex1( myTextureDark, (uint8_t)1 );
    
    gl::drawSolidRect(Rectf(0.f,0.f,getWindowSize().x,getWindowSize().y));
}

CINDER_APP( w2_ShaderImageApp, RendererGl )
