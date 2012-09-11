#include "cinder\gl\gl.h"

using namespace ci;

class EllipseDominique
{
public:
	EllipseDominique();
	EllipseDominique(Vec2f center, float x_radius, float y_radius);
	void update();
	void draw();
private:
	Vec2f center_;
	float x_radius_, y_radius_;
};