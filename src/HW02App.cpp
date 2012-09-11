#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "EllipseDominique.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings( Settings *settings );
private:
	EllipseDominique *my_ellipse, *her_ellipse;
};

void HW02App::setup()
{
	my_ellipse = new EllipseDominique(Vec2f(400.0f,300.0f),100.0f,50.0f);
	//her_ellipse = new EllipseDominique(
}

void HW02App::mouseDown( MouseEvent event )
{
}

void HW02App::update()
{
}

void HW02App::draw()
{
	my_ellipse->draw();
}

void HW02App::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

CINDER_APP_BASIC( HW02App, RendererGl )
