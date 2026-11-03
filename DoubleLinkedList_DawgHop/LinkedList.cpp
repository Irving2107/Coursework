// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr) {}

LinkedList::~LinkedList()
{
  LinkedNode *temp = head_;

  while (temp != nullptr)
  {
    LinkedNode *next = temp->getNextLinkedNode();
    delete temp;
    temp = next;
  }

  head_ = nullptr;
  tail_ = nullptr;
}

bool LinkedList::isEmpty()
{
  return head_ == nullptr;
}

int LinkedList::getLength()
{
  int count = 0;
  LinkedNode *temp = head_;

  while (temp != nullptr)
  {
    count++;
    temp = temp->getNextLinkedNode();
  }

  return count;
}

void LinkedList::insert(Card data)
{
  if (isEmpty())
  {
    LinkedNode *newLinkedNode = new LinkedNode(data);
    head_ = newLinkedNode;
    tail_ = newLinkedNode;
    newLinkedNode->setNextLinkedNode(nullptr);
    newLinkedNode->setPrevLinkedNode(nullptr);
  }
  else
  {
    insertLinkedNode(tail_, data);
  }
}

void LinkedList::printList()
{
  if (isEmpty())
  {
    std::cerr << "No list to be printed" << std::endl;
    return;
  }

  LinkedNode *temp = head_;
  while (temp != nullptr)
  {
    std::cout << temp->getValue().print() << " -> ";
    temp = temp->getNextLinkedNode();
  }
  std::cout << "x" << std::endl;
}

void LinkedList::setHead(LinkedNode *head)
{
  head_ = head;
}

LinkedNode *LinkedList::getHead()
{
  return head_;
}

void LinkedList::setTail(LinkedNode *tail)
{
  tail_ = tail;
}

LinkedNode *LinkedList::getTail()
{
  return tail_;
}

void LinkedList::insertLinkedNode(LinkedNode *node, Card data)
{
  if (node == nullptr)
  {
    return;
  }

  LinkedNode *newLinkedNode = new LinkedNode(data);
  // setting the next linked node
  newLinkedNode->setNextLinkedNode(node->getNextLinkedNode());
  node->setNextLinkedNode(newLinkedNode);

  if (node == tail_)
  {
    tail_ = newLinkedNode;
  }
}