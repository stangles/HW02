#include "TiledShapeNode.h"

TiledShapeNode::TiledShapeNode(TiledShape *data, TiledShapeNode *next)
{
	data_ = data;
	next_ = next;
}

TiledShapeNode* TiledShapeNode::next()
{
	return next_;
}

void TiledShapeNode::update()
{
	data_->update();
}

void TiledShapeNode::draw()
{
	data_->draw();
}