#include "TiledShape.h"
#define NULL 0

class TiledShapeNode {
public:
	TiledShapeNode(TiledShape *data);
	TiledShapeNode(TiledShapeNode *prev, TiledShapeNode *next);
	TiledShapeNode(TiledShape *data, TiledShapeNode *prev, TiledShapeNode *next);
	void setPrev(TiledShapeNode *prev);
	void setNext(TiledShapeNode *next);
	TiledShapeNode* prev();
	TiledShapeNode* next();
	void update();
	void draw();
private:
	TiledShape *data_;
	TiledShapeNode *prev_,*next_;
};