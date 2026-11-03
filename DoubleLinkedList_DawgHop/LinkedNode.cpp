// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "LinkedNode.h"

LinkedNode::LinkedNode() : nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
  Card defaultCard;
  setValue(defaultCard);
}

LinkedNode::LinkedNode(Card data) : nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
  setValue(data);
}

LinkedNode::~LinkedNode() {}

LinkedNode *LinkedNode::getNextLinkedNode()
{
  return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode *nextLinkedNode)
{
  nextLinkedNode_ = nextLinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
  return nextLinkedNode_ != nullptr;
}

LinkedNode *LinkedNode::getPrevLinkedNode()
{
  return prevLinkedNode_;
}

void LinkedNode::setPrevLinkedNode(LinkedNode *prevLinkedNode)
{
  prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasPrevLinkedNode()
{
  return prevLinkedNode_ != nullptr;
}