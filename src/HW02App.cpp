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
	void generateList();
	void keyDown(KeyEvent event);
	void update();
	void draw();
	void drawList();
	void prepareSettings(Settings *settings);
private:
	TiledShapeNode *node_one,*node_two,*node_three,*node_four;
	bool slash_is_pressed;
	int num_items;
	TiledShapeNode *tmp;
};

void HW02App::setup()
{
	slash_is_pressed = false;
	generateList();
}

void HW02App::generateList()
{
	num_items = 2;
	node_two = new TiledShapeNode(new TiledCircle(Vec2f(450.0f,250.0f),70.0f,Color8u(0,0,255)),node_one);
	node_one = new TiledShapeNode(new TiledEllipse(Vec2f(400.0f,300.0f),100.0f,50.0f,Color8u(0,255,0)),node_two);
}

void HW02App::keyDown(KeyEvent event)
{
	if(event.getCode() == event.KEY_SLASH) 
		slash_is_pressed = !slash_is_pressed;
}

void HW02App::update()
{
}

void HW02App::draw()
{
	node_two->next()->draw();
	//drawList();
	//if(slash_is_pressed)
	//	my_node->draw();
}

void HW02App::drawList()
{
	TiledShapeNode *tmp = node_one;
	int i;
	for(i=0; i<num_items; i++)
	{
		tmp->draw();
		tmp = tmp->next();
	}
	i = 0;
}

void HW02App::prepareSettings(Settings *settings){
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

CINDER_APP_BASIC(HW02App, RendererGl)
