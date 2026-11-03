// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : LinkedList() {}

DoubleLinkedList::~DoubleLinkedList() {}

void DoubleLinkedList::insertLinkedNode(LinkedNode *node, Card data)
{
  if (node == nullptr)
  {
    return;
  }

  LinkedNode *oldNext = node->getNextLinkedNode();
  LinkedNode *newLinkedNode = new LinkedNode(data);
  newLinkedNode->setNextLinkedNode(node->getNextLinkedNode());
  newLinkedNode->setPrevLinkedNode(node);

  if (oldNext != nullptr)
  {
    oldNext->setPrevLinkedNode(newLinkedNode);
  }

  node->setNextLinkedNode(newLinkedNode);

  if (node == getTail())
  {
    setTail(newLinkedNode);
  }
}

void DoubleLinkedList::printList()
{
  if (isEmpty())
  {
    std::cerr << "No list to be printed" << std::endl;
    return;
  }

  LinkedNode *temp = getHead();
  while (temp != nullptr)
  {
    std::cout << temp->getValue().print() << " <--> ";
    temp = temp->getNextLinkedNode();
  }
  std::cout << "x" << std::endl;
}

void DoubleLinkedList::deleteNode(Card c)
{
  if (getHead()->getFaceVal() == c.getFaceVal()) // case #1 head deletion
  {
    if (getHead()->getNextLinkedNode() != nullptr) // case #1.2 multi node list
    {
      LinkedNode *newHead = getHead()->getNextLinkedNode();
      getHead()->getNextLinkedNode()->setPrevLinkedNode(nullptr);
      getHead()->setNextLinkedNode(nullptr);
      delete getHead();
      setHead(newHead);
    }
    else // case #1.3 single node list
    {
      delete getHead();
      setHead(nullptr);
      setTail(nullptr);
    }
  }
  else if (getTail()->getFaceVal() == c.getFaceVal()) // case #2 tail deletion
  {
    LinkedNode *newTail = getTail()->getPrevLinkedNode();
    newTail->setNextLinkedNode(nullptr);
    getTail()->setPrevLinkedNode(nullptr);
    delete getTail();
    setTail(newTail);
  }
  else // case #3 and case #4. middle deletion and not found
  {
    LinkedNode *curNode = getHead();
    LinkedNode *delNode = nullptr;
    // scan the list for the node to delete
    while (curNode->getNextLinkedNode() != nullptr)
    {
      if (c.getFaceVal() == curNode->getValue().getFaceVal())
      {
        delNode = curNode; // node found
        break;
      }
      curNode = curNode->getNextLinkedNode();
    }
    if (delNode != nullptr) // if node is found
    {
      delNode->getPrevLinkedNode()->setNextLinkedNode(delNode->getNextLinkedNode());
      delNode->getNextLinkedNode()->setPrevLinkedNode(delNode->getPrevLinkedNode());
      delNode->setNextLinkedNode(nullptr);
      delNode->setPrevLinkedNode(nullptr);
      delete delNode;
    }
    else // didn't find the node to delete
    {
      std::cerr << "Node with data " << c.print() << " not found in the list." << std::endl;
    }
  }
}