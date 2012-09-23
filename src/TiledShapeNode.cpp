#include "TiledShapeNode.h"

TiledShapeNode::TiledShapeNode()
{
	data_ = NULL;
	prev_ = NULL;
	next_ = NULL;
}

TiledShapeNode::TiledShapeNode(TiledShape *data, TiledShapeNode *prev, TiledShapeNode *next)
{
	data_ = data;
	prev_ = prev;
	next_ = next;
}

void TiledShapeNode::setData(TiledShape *data)
{
	data_ = data;
}

TiledShape* TiledShapeNode::getData()
{
	return this->data_;
}

void TiledShapeNode::setPrev(TiledShapeNode *prev)
{
	this->prev_ = prev;
}

void TiledShapeNode::setNext(TiledShapeNode *next)
{
	this->next_ = next;
}

TiledShapeNode* TiledShapeNode::getPrev()
{
	return prev_;
}

TiledShapeNode* TiledShapeNode::getNext()
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