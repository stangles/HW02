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

void TiledEllipse::draw()
{
	gl::color(color_);
	gl::drawSolidEllipse(center_,x_radius_,y_radius_);
}