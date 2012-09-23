#include "cinder\app\AppBasic.h"
#include "cinder\gl\gl.h"
#include "TiledShape.h"
#include "TiledEllipse.h"
#include "TiledRectangle.h"
#include "TiledCircle.h"
#include "TiledShapeNode.h"
#include "cinder\app\KeyEvent.h"
#include "cinder\text.h"
#include "cinder\gl\Texture.h"

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
	void displayWindow();
private:
	bool slash_is_pressed;
	int num_items;
	TiledShapeNode *tmp;
	TextBox *win_text;
	gl::Texture *win_texture;
};

void HW02App::setup()
{
	//text box setup
	slash_is_pressed = true;
	win_text = new TextBox();
	win_text->setSize(Vec2i(512,512));
	win_text->setAlignment(TextBox::CENTER);
	win_text->setText("Hello, World!");
	win_texture = new gl::Texture(win_text->render());

	generateList();
}


void HW02App::displayWindow()
{


}

void HW02App::generateList()
{
	num_items = 2;
}

void HW02App::keyDown(KeyEvent event)
{
	int key_code = event.getCode();
	switch(key_code) 
	{
	case event.KEY_SLASH:
		slash_is_pressed = !slash_is_pressed;
		break;
	}
}

void HW02App::update()
{
}

void HW02App::draw()
{
	gl::clear();
	if(slash_is_pressed) 
	{
		gl::draw(*win_texture);
	}
		
}

void HW02App::drawList()
{
	
}

void HW02App::prepareSettings(Settings *settings){
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60.0f);
}

CINDER_APP_BASIC(HW02App, RendererGl)
