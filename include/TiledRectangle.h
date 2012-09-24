/*
* Author: Steven Angles
*/
#include "cinder\gl\gl.h"
#include "TiledShape.h"

using namespace ci;

class TiledRectangle:public TiledShape {
public:
	TiledRectangle(float x1, float y1, float x2, float y2, ColorA color);
	void update();
	void draw(Vec2i mouse_pos);
	bool isInside(Vec2i mouse_pos);
	void dragMove(Vec2i mouse_pos);
private:
	int last_x_pos,last_y_pos;
	float x1_, y1_, x2_, y2_;
	ColorA color_;
};