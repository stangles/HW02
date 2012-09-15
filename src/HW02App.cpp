#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "TiledShape.h"
#include "TiledEllipse.h"
#include "TiledRectangle.h"
#include "TiledCircle.h"
#include "TiledShapeNode.h"
#include "cinder\app\KeyEvent.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
public:
	void setup();
	void keyDown(KeyEvent event);
	void update();
	void draw();
	void prepareSettings( Settings *settings );
private:
	TiledEllipse *my_ellipse;
	TiledShapeNode *my_node;
	bool slash_is_pressed;
};

void HW02App::setup()
{
	my_ellipse = new TiledEllipse(Vec2f(400.0f,300.0f),100.0f,50.0f,Color8u(0,255,0));
	my_node = new TiledShapeNode(my_ellipse, my_node);
	slash_is_pressed = false;
}

void HW02App::keyDown( KeyEvent event )
{
	if(event.getCode() == event.KEY_SLASH) 
		slash_is_pressed = !slash_is_pressed;
}

void HW02App::update()
{
}

void HW02App::draw()
{
	gl::clear();
	if(slash_is_pressed)
		my_node->draw();
}

void HW02App::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

CINDER_APP_BASIC( HW02App, RendererGl )
