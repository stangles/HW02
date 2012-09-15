#include "TiledShapeNode.h"

TiledShapeNode::TiledShapeNode(TiledShape *data, TiledShapeNode *next)
{
	data_ = data;
	next_ = next;
}

void TiledShapeNode::update()
{
	data_->update();
}

void TiledShapeNode::draw()
{
	data_->draw();
}