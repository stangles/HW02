#include "cinder\gl\gl.h"
#include "TiledShape.h"

using namespace ci;

class TiledEllipse:public TiledShape {
public:
	TiledEllipse(Vec2f center, float x_radius, float y_radius, Color8u color);
	void update();
	void draw();
private:
	Vec2f center_;
	float x_radius_, y_radius_;
	Color8u color_;
};