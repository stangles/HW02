#include "TiledEllipse.h"
#include "cinder\gl\gl.h"

using namespace ci;

TiledEllipse::TiledEllipse(Vec2f center, float x_radius, float y_radius, Color8u color)
{
	center_ = center;
	x_radius_ = x_radius;
	y_radius_ = y_radius;
	color_ = color;
}

void TiledEllipse::update()
{
}

void TiledEllipse::draw(Vec2i mouse_pos)
{
	if(this->isInside(mouse_pos))
		gl::color(Color8u(255,255,255));
	else
		gl::color(color_);
	gl::drawSolidEllipse(center_,x_radius_,y_radius_);
}

bool TiledEllipse::isInside(Vec2i mouse_pos)
{
	bool check = ((pow((((float) mouse_pos.x) - center_.x), 2.0f)/(pow(x_radius_,2.0f)) +
		pow((((float) mouse_pos.y) - center_.x), 2.0f)/(pow(y_radius_,2.0f))) <= 1.0f);
	return check;
}

void TiledEllipse::dragMove(Vec2i mouse_pos)
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