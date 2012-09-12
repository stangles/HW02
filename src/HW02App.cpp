#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "TiledEllipse.h"
#include "TiledEllipseList.h"

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
	TiledEllipse *my_ellipse, *her_ellipse;
};

void HW02App::setup()
{
	my_ellipse = new TiledEllipse(Vec2f(400.0f,300.0f),100.0f,50.0f,Color8u(0,255,0));
	her_ellipse = new TiledEllipse(Vec2f(400.0f,275.0f),100.0f,50.0f,Color8u(0,0,255));
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
	her_ellipse->draw();
}

void HW02App::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

CINDER_APP_BASIC( HW02App, RendererGl )
