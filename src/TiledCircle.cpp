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