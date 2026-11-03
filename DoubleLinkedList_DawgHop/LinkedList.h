// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"
#include <iostream>

class LinkedList : public LinkedNode
{
public:
  LinkedList();
  ~LinkedList();
  bool isEmpty();
  int getLength();
  void insert(Card data);
  void printList();
  void setHead(LinkedNode *head);
  LinkedNode *getHead();
  void setTail(LinkedNode *tail);
  LinkedNode *getTail();

private:
  virtual void insertLinkedNode(LinkedNode *node, Card data);
  LinkedNode *head_;
  LinkedNode *tail_;
};
#endif // LINKEDLIST_H