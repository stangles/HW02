#include "TiledCircle.h"
#include "cinder\gl\gl.h"

using namespace ci;

TiledCircle::TiledCircle(Vec2f center, float radius, Color8u color)
{
	center_ = center;
	radius_ = radius;
	color_ = color;
	last_x_pos = 0;
	last_y_pos = 0;
}

void TiledCircle::update()
{
}

void TiledCircle::draw(Vec2i mouse_pos)
{
	if(this->isInside(mouse_pos))
		gl::color(Color8u(255,255,255));
	else
		gl::color(color_);
	gl::drawSolidCircle(center_, radius_);
}

bool TiledCircle::isInside(Vec2i mouse_pos)
{
	return ((pow((((float) mouse_pos.x) - center_.x), 2.0f) + 
		pow((((float) mouse_pos.y) - center_.y), 2.0f)) < pow(radius_, 2.0f));
}

void TiledCircle::dragMove(Vec2i mouse_pos)
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

	this->center_.x += net_x;
	this->center_.y += net_y;

	last_x_pos = x;
	last_y_pos = y;
}