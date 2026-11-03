// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "Node.h"

Node::Node()
{
  initialize(0, 0);
}

Node::Node(Card data)
{
  data_ = data;
}

Node::~Node() {}

Card Node::getValue()
{
  return data_;
}

void Node::setValue(Card data)
{
  data_ = data;
}

Card Node::getData()
{
  return data_;
}