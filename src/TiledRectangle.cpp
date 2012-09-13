#include "TiledRectangle.h"

using namespace ci;

TiledRectangle::TiledRectangle(float x1, float y1, float x2, float y2, Color8u color)
{
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	color_ = color;
}

void TiledRectangle::update()
{
}

void TiledRectangle::draw()
{
	gl::color(color_);
	gl::drawSolidRoundedRect(Rectf(x1_, y1_, x2_, y2_), 10.0f);
}