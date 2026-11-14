// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef NODE_H
#define NODE_H

class Node
{
public:
  Node();
  Node(int data);
  ~Node();
  int getValue() const;
  void setValue(int value);

private:
  int data_;
};
#endif // NODE_H