// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"

class LinkedNode : public Node
{
public:
  LinkedNode();
  LinkedNode(Card data);
  ~LinkedNode();
  LinkedNode *getNextLinkedNode();
  void setNextLinkedNode(LinkedNode *nextLinkedNode);
  bool hasNextLinkedNode();
  LinkedNode *getPrevLinkedNode();
  void setPrevLinkedNode(LinkedNode *prevLinkedNode);
  bool hasPrevLinkedNode();

private:
  LinkedNode *nextLinkedNode_;
  LinkedNode *prevLinkedNode_;
};
#endif // LINKEDNODE_H