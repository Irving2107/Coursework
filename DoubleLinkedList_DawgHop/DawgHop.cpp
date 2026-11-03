// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "DawgHop.h"

DawgHop::DawgHop() {}

DawgHop::~DawgHop() {}

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
    LinkedNode *nextNode = current->getNextLinkedNode();
    LinkedNode *prevNode = current->getPrevLinkedNode();

    while (prevNode != nullptr &&
           prevNode->getValue().getFaceVal() >
               current->getValue().getFaceVal())
    {
      prevNode = prevNode->getPrevLinkedNode();
      dawgHops++;
    }

    if (prevNode != current->getPrevLinkedNode())
    {
      if (current->hasNextLinkedNode())
      {
        current->getNextLinkedNode()->setPrevLinkedNode(
            current->getPrevLinkedNode());
      }
      else
      {
        dll->setTail(current->getPrevLinkedNode());
      }

      if (current->hasPrevLinkedNode())
      {
        current->getPrevLinkedNode()->setNextLinkedNode(
            current->getNextLinkedNode());
      }
      else
      {
        dll->setHead(current->getNextLinkedNode());
      }

      if (prevNode == nullptr)
      {
        current->setNextLinkedNode(dll->getHead());
        current->setPrevLinkedNode(nullptr);

        dll->getHead()->setPrevLinkedNode(current);
        dll->setHead(current);
      }
      else
      {
        current->setNextLinkedNode(prevNode->getNextLinkedNode());
        current->setPrevLinkedNode(prevNode);

        if (prevNode->hasNextLinkedNode())
        {
          prevNode->getNextLinkedNode()->setPrevLinkedNode(current);
        }
        else
        {
          dll->setTail(current);
        }

        prevNode->setNextLinkedNode(current);
      }
    }

    current = nextNode;
  }
}