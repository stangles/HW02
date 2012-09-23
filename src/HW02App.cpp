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
	void mouseDown(MouseEvent event);
	void update();
	void draw();
	void drawList();
	void prepareSettings(Settings *settings);
	void listClickHandler(Vec2i mouse_pos);
	void bringToFront(TiledShapeNode *front);
private:
	bool slash_is_pressed;
	TextBox *win_text;
	gl::Texture *win_texture;
	TiledShapeNode *sentinel;
	TiledShapeNode *node_one,*node_two;
};

void HW02App::setup()
{
	//text box setup
	slash_is_pressed = true;
	win_text = new TextBox();
	win_text->setSize(Vec2i(800,600));
	win_text->setAlignment(TextBox::CENTER);
	win_text->setText("Hello, World!");
	win_text->setBackgroundColor(ColorA(0.5f,0.5f,0.5f,0.1f));
	win_text->setFont(Font("Tahoma", 18));
	win_texture = new gl::Texture(win_text->render());

	generateList();
}

void HW02App::generateList()
{
	sentinel = new TiledShapeNode();
	node_one = new TiledShapeNode();
	node_two = new TiledShapeNode();
	node_one->setData(new TiledCircle(Vec2f(400.0f,300.0f),50.0f,Color8u(0,255,0)));
	node_one->setPrev(sentinel);
	node_two->setData(new TiledCircle(Vec2f(450.0f,300.0f),50.0f,Color8u(0,0,255)));
	node_two->setPrev(node_one);
	node_two->setNext(sentinel);
	sentinel->setPrev(node_two);
	sentinel->setNext(node_one);
	node_one->setNext(node_two);

}

void HW02App::listClickHandler(Vec2i mouse_pos)
{
	TiledShapeNode *cur = sentinel->getPrev(); //since those drawn last occlude those drawn first
	bool exit = false;
	do {
		if(cur->getData()->isInside(mouse_pos))
		{
			bringToFront(cur);
			exit = true;
		}

		cur = cur->getPrev();
	} while (cur != sentinel && !exit);
}

void HW02App::bringToFront(TiledShapeNode *front)
{
	//Remove selected from list
	front->getPrev()->setNext(front->getNext());
	front->getNext()->setPrev(front->getPrev());

	//Insert it to the correct part of list
	front->setNext(sentinel);
	front->setPrev(sentinel->getPrev());

	//Update nodes before and after our new "front" node
	front->getPrev()->setNext(front);
	front->getNext()->setPrev(front);
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

void HW02App::mouseDown(MouseEvent event)
{
	listClickHandler(event.getPos());
}

void HW02App::update()
{
}

void HW02App::draw()
{
	gl::clear();
	drawList();
	if(slash_is_pressed) 
	{
		gl::draw(*win_texture);
	}
		
}

void HW02App::drawList()
{
	TiledShapeNode *cur = sentinel->getNext();
	do {
		cur->getData()->draw();
		cur = cur->getNext();
	} while(cur != sentinel);
}

void HW02App::prepareSettings(Settings *settings){
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60.0f);
}

CINDER_APP_BASIC(HW02App, RendererGl)
