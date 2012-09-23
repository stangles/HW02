#include "TiledShapeNode.h"

TiledShapeNode::TiledShapeNode(TiledShape *data)
{
	data_ = data;
	prev_ = NULL;
	next_ = NULL;
}

TiledShapeNode::TiledShapeNode(TiledShapeNode *prev, TiledShapeNode *next)
{
	data_ = NULL;
	prev_ = prev;
	next_ = next;
}

TiledShapeNode::TiledShapeNode(TiledShape *data, TiledShapeNode *prev, TiledShapeNode *next)
{
	data_ = data;
	prev_ = prev;
	next_ = next;
}

void TiledShapeNode::setPrev(TiledShapeNode *prev)
{
	this->prev_ = prev;
}

void TiledShapeNode::setNext(TiledShapeNode *next)
{
	this->next_ = next;
}

TiledShapeNode* TiledShapeNode::prev()
{
	return prev_;
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