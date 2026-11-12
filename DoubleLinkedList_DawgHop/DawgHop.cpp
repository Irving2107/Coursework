// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "DawgHop.h"

DawgHop::DawgHop() {}

DawgHop::~DawgHop() {}
// Originally swapped nodes, but now swaps Card objects
void DawgHop::insertionSort(DoubleLinkedList *dll, int &dawgHops)
{
  if (dll == nullptr || dll->isEmpty())
  {
    std::cerr << "No list to be sorted" << std::endl;
    return;
  }

  LinkedNode *current = dll->getHead()->getNextLinkedNode();

  while (current != nullptr)
  {
    LinkedNode *prevNode = current->getPrevLinkedNode();

    while (prevNode != nullptr &&
           prevNode->getValue().getFaceVal() >
               current->getValue().getFaceVal())
    {
      Card temp = current->getValue();

      current->setValue(prevNode->getValue());
      prevNode->setValue(temp);

      dawgHops++;

      current = prevNode;
      prevNode = current->getPrevLinkedNode();
    }

    current = current->getNextLinkedNode();
  }
}