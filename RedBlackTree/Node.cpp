// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "Node.h"

Node::Node()
{
  data_ = 0;
}

Node::Node(int data)
{
  data_ = data;
}

Node::~Node() {}

int Node::getValue() const
{
  return data_;
}

void Node::setValue(int value)
{
  data_ = value;
}