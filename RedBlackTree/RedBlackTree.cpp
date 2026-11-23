// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree() {}

RedBlackTree::RedBlackTree(const RedBlackTree &other) : BinarySearchTree(other) {}

RedBlackTree::~RedBlackTree() {}

void RedBlackTree::insert(int data)
{
  BinarySearchTree::insert(data);

  TreeNode *current = getRoot();
  while (current != nullptr)
  {
    if (current->getValue() == data)
    {
      current->setColor(RED);
      break;
    }
    else if (data < current->getValue())
    {
      current = current->getLeftChild();
    }
    else
    {
      current = current->getRightChild();
    }
  }

  if (getRoot() != nullptr)
  {
    getRoot()->setColor(BLACK);
  }
}
