#include "TiledShape.h"

class TiledShapeNode {
public:
	TiledShapeNode(TiledShape *data, TiledShapeNode *next);
	TiledShapeNode* next();
	void update();
	void draw();
private:
	TiledShape *data_;
	TiledShapeNode *next_;
};