#include "TiledRectangle.h"

using namespace ci;

TiledRectangle::TiledRectangle(float x1, float y1, float x2, float y2, ColorA color)
{
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	color_ = color;
	last_x_pos = 0;
	last_y_pos = 0;
}

bool TiledRectangle::isInside(Vec2i mouse_pos)
{
	return ((mouse_pos.x >= x1_) && (mouse_pos.x <= x2_)
		&& (mouse_pos.y >= y1_) && (mouse_pos.y <= y2_));
}
void TiledRectangle::update()
{
}

void TiledRectangle::draw(Vec2i mouse_pos)
{
	if(this->isInside(mouse_pos))
		gl::color(ColorA(1.0f,1.0f,1.0f,0.7f));
	else
		gl::color(color_);
	gl::drawSolidRect(Rectf(x1_, y1_, x2_, y2_));
}

void TiledRectangle::dragMove(Vec2i mouse_pos)
{
	int x = mouse_pos.x;
	int y = mouse_pos.y;

	if(last_x_pos == 0 && last_y_pos == 0)
	{
		last_x_pos = x;
		last_y_pos = y;
	}

	int net_x = x - last_x_pos;
	int net_y = y - last_y_pos;

	this->x1_ += (float) net_x;
	this->x2_ += (float) net_x;
	this->y1_ += (float) net_y;
	this->y2_ += (float) net_y;

	last_x_pos = x;
	last_y_pos = y;
}