#include "cinder\gl\gl.h"
#include "TiledShape.h"

using namespace ci;

class TiledCircle:public TiledShape {
public:
	TiledCircle(Vec2f center, float radius, Color8u color);
	void update();
	void draw(Vec2i mouse_pos);
	bool isInside(Vec2i mouse_pos);
	void dragMove(Vec2i mouse_pos);
private:
	Vec2f center_;
	float radius_;
	Color8u color_;
	int last_x_pos,last_y_pos;
};