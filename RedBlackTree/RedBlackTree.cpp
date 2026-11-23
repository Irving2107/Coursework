// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree() {}

RedBlackTree::RedBlackTree(const RedBlackTree &other) : BinarySearchTree(other) {}

RedBlackTree::~RedBlackTree() {}

void RedBlackTree::insert(int data)
{
  BinarySearchTree::insert(data);
  TreeNode *root = getRoot();
  TreeNode *current = root;
  TreeNode *newNode = nullptr;

  // find node
  while (current != nullptr)
  {
    if (data < current->getValue())
    {
      current = current->getLeftChild();
    }
    else if (data > current->getValue())
    {
      current = current->getRightChild();
    }
    else
    {
      newNode = current;
      current = current->getRightChild();
    }
  }

  if (newNode != nullptr)
  {
    newNode->setColor(RED);
    balanceColor(root, newNode);
  }

  setRoot(root);
  if (getRoot() != nullptr)
  {
    getRoot()->setColor(BLACK);
  }
}

void RedBlackTree::rotateLeft(TreeNode *&root, TreeNode *&newNode)
{
  if (newNode == nullptr || newNode->getRightChild() == nullptr)
  {
    return;
  }

  // move right child's left subtree to the new node's right
  TreeNode *rightChild = newNode->getRightChild();

  newNode->setRightChild(rightChild->getLeftChild());
  if (rightChild->getLeftChild() != nullptr)
  {
    rightChild->getLeftChild()->setParent(newNode);
  }

  // connect right child to old parent
  rightChild->setParent(newNode->getParent());
  if (newNode->getParent() == nullptr)
  {
    root = rightChild;
  }
  else if (newNode == newNode->getParent()->getLeftChild())
  {
    newNode->getParent()->setLeftChild(rightChild);
  }
  else
  {
    newNode->getParent()->setRightChild(rightChild);
  }

  // make original node left child
  rightChild->setLeftChild(newNode);
  newNode->setParent(rightChild);
}

void RedBlackTree::rotateRight(TreeNode *&root, TreeNode *&newNode)
{
  if (newNode == nullptr || newNode->getLeftChild() == nullptr)
  {
    return;
  }

  TreeNode *leftChild = newNode->getLeftChild();
  newNode->setLeftChild(leftChild->getRightChild());

  if (leftChild->getRightChild() != nullptr)
  {
    leftChild->getRightChild()->setParent(newNode);
  }
  leftChild->setParent(newNode->getParent());

  if (newNode->getParent() == nullptr)
  {
    root = leftChild;
  }
  else if (newNode == newNode->getParent()->getRightChild())
  {
    newNode->getParent()->setRightChild(leftChild);
  }
  else
  {
    newNode->getParent()->setLeftChild(leftChild);
  }

  leftChild->setRightChild(newNode);
  newNode->setParent(leftChild);
}

void RedBlackTree::balanceColor(TreeNode *&root, TreeNode *&newNode)
{
  while (newNode != root && newNode->getParent() != nullptr && newNode->getParent()->getColor() == RED)
  {
    TreeNode *parent = newNode->getParent();
    TreeNode *grandparent = parent->getParent();

    if (grandparent == nullptr)
    {
      break;
    }

    // parent is the left child of grandparent
    if (parent == grandparent->getLeftChild())
    {
      TreeNode *uncle = grandparent->getRightChild();

      // 1: Uncle is red
      if (uncle != nullptr && uncle->getColor() == RED)
      {
        parent->setColor(BLACK);
        uncle->setColor(BLACK);
        grandparent->setColor(RED);
        newNode = grandparent;
      }
      else
      {
        // 2: rotate left at parent
        if (newNode == parent->getRightChild())
        {
          newNode = parent;
          rotateLeft(root, newNode);

          parent = newNode->getParent();
          grandparent = parent->getParent();
        }

        // 3: rotate right at grandparent
        parent->setColor(BLACK);
        grandparent->setColor(RED);

        rotateRight(root, grandparent);
      }
    }
    // parent is the right child of grandparent
    else
    {
      TreeNode *uncle = grandparent->getLeftChild();

      if (uncle != nullptr && uncle->getColor() == RED)
      {
        parent->setColor(BLACK);
        uncle->setColor(BLACK);
        grandparent->setColor(RED);

        newNode = grandparent;
      }
      else
      {
        if (newNode == parent->getLeftChild())
        {
          newNode = parent;
          rotateRight(root, newNode);
          parent = newNode->getParent();
          grandparent = parent->getParent();
        }

        parent->setColor(BLACK);
        grandparent->setColor(RED);
        rotateLeft(root, grandparent);
      }
    }
  }

  if (root != nullptr)
  {
    root->setColor(BLACK);
  }
}