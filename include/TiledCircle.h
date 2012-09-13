#include "cinder\gl\gl.h"

using namespace ci;

class TiledCircle {
public:
	TiledCircle(Vec2f center, float radius, Color8u color);
	void update();
	void draw();
private:
	Vec2f center_;
	float radius_;
	Color8u color_;
};