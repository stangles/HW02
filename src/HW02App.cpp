/*
* Author: Steven Angles
* 
*/
#include "cinder\app\AppBasic.h"
#include "cinder\gl\gl.h"
#include "TiledShape.h"
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
	void mouseDrag(MouseEvent event);
	void update();
	void draw();
	void drawList();
	void prepareSettings(Settings *settings);
	void listClickHandler(Vec2i mouse_pos);
	void bringToFront(TiledShapeNode *front);
	void reverse();
private:
	int last_x_pos, last_y_pos;
	bool question_is_pressed,r_is_pressed;
	TextBox *win_text;
	gl::Texture *win_texture;
	TiledShapeNode *sentinel;
	TiledShapeNode *node_one,*node_two,*node_three,*node_four;
};

void HW02App::setup()
{
	r_is_pressed = false;
	//text box setup
	question_is_pressed = true;
	win_text = new TextBox();
	win_text->setSize(Vec2i(800,600));
	win_text->setAlignment(TextBox::CENTER);
	win_text->setText("Hello!\nClick and drag objects. Use 'r' to reverse their order. Press '?' to show and hide this message");
	win_text->setBackgroundColor(ColorA(0.5f,0.5f,0.5f));
	win_text->setColor(ColorA(1.0f,1.0f,1.0f));
	win_text->setFont(Font("Tahoma", 18));
	win_texture = new gl::Texture(win_text->render());

	generateList();

	last_x_pos = 0;
	last_y_pos = 0;

	//for transparency
	gl::enableAlphaBlending();
}

void HW02App::generateList()
{
	sentinel = new TiledShapeNode();
	node_one = new TiledShapeNode();
	node_two = new TiledShapeNode();
	node_three = new TiledShapeNode();
	node_four = new TiledShapeNode();
	sentinel->setPrev(node_four);
	sentinel->setNext(node_one);
	node_one->setPrev(sentinel);
	node_one->setNext(node_two);
	node_two->setPrev(node_one);
	node_two->setNext(node_three);
	node_three->setPrev(node_two);
	node_three->setNext(node_four);
	node_four->setPrev(node_three);
	node_four->setNext(sentinel);
	node_one->setData(new TiledRectangle(350.0f,250.0f,450.0f,300.0f,ColorA(0.0f,0.5f,0.0f,0.4f)));
	node_two->setData(new TiledRectangle(400.0f,250.0f,450.0f,350.0f,ColorA(0.0f,0.0f,0.5f,0.4f)));
	node_three->setData(new TiledCircle(Vec2f(500.0f,200.0f),100.0f,ColorA(0.5f,0.0f,0.0f,0.4f)));
	node_four->setData(new TiledCircle(Vec2f(300.0f,400.0f),100.0f,ColorA(0.0f,0.5f,0.5f,0.4f)));
}

/*
* Handling for the list when the mouse is clicked
*/
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

/*
* Reorders the list
*/
void HW02App::reverse()
{
	TiledShapeNode *cur = sentinel;
	TiledShapeNode *tmp;
	do {
		tmp = cur->getNext();
		cur->setNext(cur->getPrev());
		cur->setPrev(tmp);
		cur = tmp;
	} while(cur != sentinel);

}

/*
* Idea borrow from Cooper Riley: github.com/rileycr
*/
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

/*
* Called when a key board button is pressed
*/
void HW02App::keyDown(KeyEvent event)
{
	if(event.getChar() == '?')
		question_is_pressed = !question_is_pressed;
	if(event.getCode() == event.KEY_r)
		r_is_pressed = true;
}

/*
* Called when the mouse is clicked
*/
void HW02App::mouseDown(MouseEvent event)
{
	listClickHandler(event.getPos());
}

/*
* Fires when mouse is clicked and moved simultaneously
*/
void HW02App::mouseDrag(MouseEvent event)
{
	TiledShape *tmp = sentinel->getPrev()->getData();
	if(tmp->isInside(event.getPos()))
		tmp->dragMove(event.getPos());
}

void HW02App::update()
{
	if(r_is_pressed)
	{
		reverse();
		r_is_pressed = false;
	}
}

void HW02App::draw()
{
	gl::clear();
	drawList();
	if(question_is_pressed) 
	{
		gl::draw(*win_texture);
	}
}

/*
* Called from draw() so it's a bit cleaner
*/
void HW02App::drawList()
{
	TiledShapeNode *cur = sentinel->getNext();
	do {
		cur->getData()->draw(getMousePos());
		cur = cur->getNext();
	} while(cur != sentinel);
}

void HW02App::prepareSettings(Settings *settings){
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60.0f);
	settings->setResizable(false);
}

CINDER_APP_BASIC(HW02App, RendererGl)
