#include "TiledShape.h"
#define NULL 0

class TiledShapeNode {
public:
	TiledShapeNode();
	TiledShapeNode(TiledShape *data, TiledShapeNode *prev, TiledShapeNode *next);
	void setData(TiledShape *data);
	TiledShape* getData();
	void setPrev(TiledShapeNode *prev);
	void setNext(TiledShapeNode *next);
	TiledShapeNode* getPrev();
	TiledShapeNode* getNext();
	void update();
	void draw();
private:
	TiledShape *data_;
	TiledShapeNode *prev_,*next_;
};