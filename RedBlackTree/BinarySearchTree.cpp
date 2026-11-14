// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#include "BinarySearchTree.h"
// #include <algorithm>

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}

// BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &other)
// {
//   if (this != &other)
//   {
//     TreeNode *newRoot = nullptr;
//     if (other.root_ != nullptr)
//     {
//       newRoot = new TreeNode(*other.root_);
//     }

//     delete root_;
//     root_ = newRoot;
//   }
// }

BinarySearchTree::BinarySearchTree(const BinarySearchTree &other) : root_(nullptr)
{
  if (other.getRoot() != nullptr)
  {
    root_ = new TreeNode(*other.getRoot());
  }
}

BinarySearchTree::~BinarySearchTree()
{
  if (root_ != nullptr)
  {
    delete root_;
    root_ = nullptr;
  }
}

void BinarySearchTree::insert(int data)
{
  TreeNode *newNode = new TreeNode(data);
  root_ = insertNode(root_, newNode);
}

void BinarySearchTree::print()
{
  std::cout << "Inorder Traversal: ";
  inorderTraversal(root_);
  std::cout << std::endl;
}

void BinarySearchTree::setRoot(TreeNode *root)
{
  root_ = root;
}

TreeNode *BinarySearchTree::getRoot() const
{
  return root_;
}

TreeNode *BinarySearchTree::insertNode(TreeNode *root, TreeNode *node)
{
  if (root == nullptr)
  {
    return node;
  }

  if (node->getValue() < root->getValue())
  {
    root->setLeftChild(insertNode(root->getLeftChild(), node));
    root->getLeftChild()->setParent(root);
  }
  else
  {
    root->setRightChild(insertNode(root->getRightChild(), node));
    root->getRightChild()->setParent(root);
  }

  return root;
}

void BinarySearchTree::inorderTraversal(TreeNode *node)
{
  if (node == nullptr)
  {
    return;
  }

  inorderTraversal(node->getLeftChild());
  std::cout << node->getValue() << " ";
  inorderTraversal(node->getRightChild());
}

int BinarySearchTree::getHeight() const
{
  return getHeight(root_);
}

int BinarySearchTree::getHeight(TreeNode *node) const
{
  if (node == nullptr)
  {
    return -1;
  }

  int leftHeight = getHeight(node->getLeftChild());
  int rightHeight = getHeight(node->getRightChild());

  // return 1 + std::max(leftHeight, rightHeight);

  if (leftHeight > rightHeight)
  {
    return 1 + leftHeight;
  }
  else
  {
    return 1 + rightHeight;
  }
}