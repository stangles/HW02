#include "cinder\gl\gl.h"
//#include "TiledShape.h"
#include "cinder\Rect.h"

using namespace ci;

class TiledRectangle {
public:
	TiledRectangle(float x1, float y1, float x2, float y2, Color8u color);
	void update();
	void draw();
private:
	float x1_, y1_, x2_, y2_;
	Color8u color_;
};