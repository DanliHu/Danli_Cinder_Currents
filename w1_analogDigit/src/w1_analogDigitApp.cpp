#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class w1_analogDigitApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void keyDown( KeyEvent event) override;
	void update() override;
	void draw() override;
    void drawLine();
    void digit1();
    void digit2();
    void digit3();
    void digit4();
    void digit5();
    void digit6();
    void digit7();
    
    void number0();
    void number1();
    void number2();
    void number3();
    void number4();
    void number5();
    void number6();
    void number7();
    void number8();
    void number9();
    
    ci::vec2 center = 0.5f * ci::vec2(ci::app::getWindowSize());
    float height = 60;
    float h2 = height/2;
    
    int displayNum = 0;
};

void w1_analogDigitApp::setup()
{
}

void w1_analogDigitApp::mouseDown( MouseEvent event )
{
}

void w1_analogDigitApp::keyDown(KeyEvent event)
{
    if (event.getChar() == '1') {
        displayNum = 1;
    }else if (event.getChar() == '2'){
        displayNum = 2;
    }else if (event.getChar() == '3'){
        displayNum = 3;
    }else if (event.getChar() == '4'){
        displayNum = 4;
    }else if (event.getChar() == '5'){
        displayNum = 5;
    }else if (event.getChar() == '6'){
        displayNum = 6;
    }else if (event.getChar() == '7'){
        displayNum = 7;
    }else if (event.getChar() == '8'){
        displayNum = 8;
    }else if (event.getChar() == '9'){
        displayNum = 9;
    }else if (event.getChar() == '0'){
        displayNum = 0;
    }else{
        displayNum = 0;
    }
}

void w1_analogDigitApp::update()
{
}

void w1_analogDigitApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    gl::pushModelView();
    gl::translate(center);
    
    //display number
    if (displayNum == 0) {
         number0();
    }else if (displayNum == 1) {
        number1();
    }else if (displayNum == 2) {
        number2();
    }else if (displayNum == 3) {
        number3();
    }else if (displayNum == 4) {
        number4();
    }else if (displayNum == 5) {
        number5();
    }else if (displayNum == 6) {
        number6();
    }else if (displayNum == 7) {
        number7();
    }else if (displayNum == 8) {
        number8();
    }else if (displayNum == 9) {
        number9();
    }else{
        number0();
    }
   
    gl::popModelView();
}

void w1_analogDigitApp::drawLine()
{
    gl::color(ci::Color(1.f,0.f,0.f));
    gl::drawSolidRect(Rectf(-10,h2,10,-h2));
    gl::drawSolidTriangle(ci::vec2(-10,h2), ci::vec2(0,40), ci::vec2(10,h2));
    gl::drawSolidTriangle(ci::vec2(-10,-h2), ci::vec2(0,-40), ci::vec2(10,-h2));
}

// ------1------
//|             |
//4             5
//|             |
// ------2------
//|             |
//6             7
//|             |
// ------3------

void w1_analogDigitApp::digit1()
{
    //1
    gl::pushModelView();
    gl::translate(0,-height-26.f);
    gl::rotate(glm::radians(90.f));
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::digit2()
{
    //2
    gl::pushModelView();
    gl::rotate(glm::radians(90.f));
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::digit3()
{
    //3
    gl::pushModelView();
    gl::translate(0,height+26.f);
    gl::rotate(glm::radians(90.f));
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::digit4()
{
    //4
    gl::pushModelView();
    gl::translate(-height+13.f,-h2-12.f);
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::digit5()
{
    //5
    gl::pushModelView();
    gl::translate(height-13.f,-h2-12.f);
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::digit6()
{
    //6
    gl::pushModelView();
    gl::translate(-height+13.f,h2+12.f);
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::digit7()
{
    //7
    gl::pushModelView();
    gl::translate(height-13.f,h2+12.f);
    drawLine();
    gl::popModelView();
}

void w1_analogDigitApp::number0(){
    digit1();
    digit4();
    digit5();
    digit6();
    digit7();
    digit3();
}

void w1_analogDigitApp::number1(){
    digit5();
    digit7();
}

void w1_analogDigitApp::number2(){
    digit1();
    digit5();
    digit2();
    digit6();
    digit3();
}

void w1_analogDigitApp::number3(){
    digit1();
    digit5();
    digit2();
    digit7();
    digit3();
}

void w1_analogDigitApp::number4(){
    digit4();
    digit2();
    digit5();
    digit7();
}

void w1_analogDigitApp::number5(){
    digit1();
    digit4();
    digit2();
    digit7();
    digit3();
}

void w1_analogDigitApp::number6(){
    digit1();
    digit4();
    digit2();
    digit7();
    digit3();
    digit6();
}

void w1_analogDigitApp::number7(){
    digit1();
    digit5();
    digit7();
}

void w1_analogDigitApp::number8(){
    digit1();
    digit2();
    digit3();
    digit4();
    digit6();
    digit5();
    digit7();
}

void w1_analogDigitApp::number9(){
    digit1();
    digit2();
    digit3();
    digit4();
    digit5();
    digit7();
}

CINDER_APP( w1_analogDigitApp, RendererGl )
