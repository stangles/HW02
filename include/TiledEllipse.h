#include "cinder\gl\gl.h"

using namespace ci;

class TiledEllipse
{
public:
	TiledEllipse();
	TiledEllipse(Vec2f center, float x_radius, float y_radius, Color8u color);
	void update();
	void draw();
private:
	Vec2f center_;
	float x_radius_, y_radius_;
	Color8u color_;
};