// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef DAWGHOP_H
#define DAWGHOP_H
#include "DoubleLinkedList.h"

class DawgHop : public DoubleLinkedList
{
public:
  DawgHop();
  ~DawgHop();
  void insertionSort(DoubleLinkedList *dll, int &dawgHops);
};
#endif // DAWGHOP_H