// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#include "BinarySearchTree.h"
// #include <algorithm>

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}

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

void BinarySearchTree::preorderTraversal(TreeNode *node)
{
  if (node == nullptr)
  {
    return;
  }

  std::cout << node->getValue() << " ";
  preorderTraversal(node->getLeftChild());
  preorderTraversal(node->getRightChild());
}

void BinarySearchTree::postorderTraversal(TreeNode *node)
{
  if (node == nullptr)
  {
    return;
  }

  postorderTraversal(node->getLeftChild());
  postorderTraversal(node->getRightChild());
  std::cout << node->getValue() << " ";
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

void BinarySearchTree::deleteNode(int data)
{
  root_ = deleteTreeNode(root_, data);
}

TreeNode *BinarySearchTree::deleteTreeNode(TreeNode *root, int data)
{
  if (root == nullptr)
  {
    return nullptr;
  }

  if (data < root->getValue())
  {
    // left subtree deletion
    root->setLeftChild(deleteTreeNode(root->getLeftChild(), data));
  }
  else if (data > root->getValue())
  {
    // right subtree deletion
    root->setRightChild(deleteTreeNode(root->getLeftChild(), data));
  }
  else
  {
    // root itself deletion
    if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr)
    {
      // 1) Leaf node

      // check parent

      delete root;
      return nullptr;
    }
    else if (root->getLeftChild() == nullptr)
    {
      // 2) has a right child
      TreeNode *node = root->getRightChild();
      root->setValue(node->getValue());
      root->setLeftChild(node->getLeftChild());
      root->setRightChild(node->getRightChild());

      // backward links for adopted children
      if (root->getLeftChild() != nullptr)
      {
        root->getLeftChild()->setParent(root);
      }

      if (root->getRightChild() != nullptr)
      {
        root->getRightChild()->setParent(root);
      }

      node->setLeftChild(nullptr);
      node->setRightChild(nullptr);
      node->setParent(nullptr);

      delete node;
      return root;
    }
    else if (root->getRightChild() == nullptr)
    {
      // 3) has a left child
      TreeNode *node = root->getLeftChild();
      root->setValue(node->getValue());
      root->setRightChild(node->getRightChild());
      root->setLeftChild(node->getLeftChild());

      // backward links for adopted children
      if (root->getRightChild() != nullptr)
      {
        root->getRightChild()->setParent(root);
      }

      if (root->getLeftChild() != nullptr)
      {
        root->getLeftChild()->setParent(root);
      }

      node->setRightChild(nullptr);
      node->setLeftChild(nullptr);
      node->setParent(nullptr);

      delete node;
      return root;
    }
    else
    {
      // 4) two children
      TreeNode *node = root->getRightChild();
      while (node != nullptr && node->getLeftChild() != nullptr)
      {
        node = node->getLeftChild();
      }

      root->setValue(node->getValue());

      root->setRightChild(deleteTreeNode(root->getRightChild(), node->getValue()));
    }
  }

  return root;
}