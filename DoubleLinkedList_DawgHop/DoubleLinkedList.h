// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "LinkedList.h"

class DoubleLinkedList : public LinkedList
{
public:
  DoubleLinkedList();
  virtual ~DoubleLinkedList();
  virtual void printList();
  virtual void insertLinkedNode(LinkedNode *node, Card data);
  virtual void deleteNode(Card c);
};
#endif // DOUBLELINKEDLIST_H