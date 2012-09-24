#ifndef TILEDSHAPE_H
#define TILEDSHAPE_H
#include "cinder\gl\gl.h"

class TiledShape {
public:
	virtual void update();
	virtual void draw();
	virtual void draw(ci::Vec2i mouse_pos);
	virtual bool isInside(ci::Vec2i mouse_pos);
	virtual void dragMove(ci::Vec2i mouse_pos);
};

#endif