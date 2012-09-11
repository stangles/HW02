#include "EllipseDominique.h"
#include "cinder\gl\gl.h"

using namespace ci;

EllipseDominique::EllipseDominique()
{
}

EllipseDominique::EllipseDominique(Vec2f center, float x_radius, float y_radius)
{
	center_ = center;
	x_radius_ = x_radius;
	y_radius_ = y_radius;
}

void EllipseDominique::update()
{
}

void EllipseDominique::draw()
{
	gl::color(0.0f,0.0f,1.0f);
	gl::drawSolidEllipse(center_,x_radius_,y_radius_);
}