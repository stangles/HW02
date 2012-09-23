#include "TiledCircle.h"
#include "cinder\gl\gl.h"

using namespace ci;

TiledCircle::TiledCircle(Vec2f center, float radius, Color8u color)
{
	center_ = center;
	radius_ = radius;
	color_ = color;
}

void TiledCircle::update()
{
}

void TiledCircle::draw()
{
	gl::color(color_);
	gl::drawSolidCircle(center_, radius_);
}

bool TiledCircle::isInside(Vec2i mouse_pos)
{
	return ((pow((((float) mouse_pos.x) - center_.x), 2.0f) + 
		pow((((float) mouse_pos.y) - center_.y), 2.0f)) < pow(radius_, 2.0f));
}
