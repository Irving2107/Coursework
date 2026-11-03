// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef NODE_H
#define NODE_H

#include "Card.h"

class Node : public Card
{
public:
  Node();
  Node(Card data);
  ~Node();
  Card getValue();
  void setValue(Card data);
  Card getData();

private:
  Card data_;
};
#endif // NODE_H