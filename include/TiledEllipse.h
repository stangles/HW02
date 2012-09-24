#include "cinder\gl\gl.h"
#include "TiledShape.h"

using namespace ci;

class TiledEllipse:public TiledShape {
public:
	TiledEllipse(Vec2f center, float x_radius, float y_radius, Color8u color);
	void update();
	void draw(Vec2i mouse_pos);
	void dragMove(Vec2i mouse_pos);
	bool isInside(Vec2i mouse_pos);
private:
	int last_x_pos,last_y_pos;
	Vec2f center_;
	float x_radius_, y_radius_;
	Color8u color_;
};