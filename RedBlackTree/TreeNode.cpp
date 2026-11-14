// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "TreeNode.h"

TreeNode::TreeNode() : TreeNode(0) {}

TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr) {}

TreeNode::TreeNode(const TreeNode &other) : Node(other.getValue()), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr)
{
  if (other.leftChild_ != nullptr)
  {
    leftChild_ = new TreeNode(*other.leftChild_);
    leftChild_->setParent(this);
  }

  if (other.rightChild_ != nullptr)
  {
    rightChild_ = new TreeNode(*other.rightChild_);
    rightChild_->setParent(this);
  }
}

TreeNode::~TreeNode()
{
  if (leftChild_ != nullptr)
  {
    delete leftChild_;
    leftChild_ = nullptr;
  }
  if (rightChild_ != nullptr)
  {
    delete rightChild_;
    rightChild_ = nullptr;
  }
  if (parent_ != nullptr)
  {
    parent_ = nullptr;
  }
}

void TreeNode::setLeftChild(TreeNode *leftChild)
{
  leftChild_ = leftChild;
}

void TreeNode::setRightChild(TreeNode *rightChild)
{
  rightChild_ = rightChild;
}

void TreeNode::setParent(TreeNode *parent)
{
  parent_ = parent;
}

TreeNode *TreeNode::getLeftChild() const
{
  return leftChild_;
}

TreeNode *TreeNode::getRightChild() const
{
  return rightChild_;
}

TreeNode *TreeNode::getParent() const
{
  return parent_;
}