// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "TreeNode.h"
#include <iostream>

class BinarySearchTree : public TreeNode
{
public:
  BinarySearchTree();
  // BinarySearchTree &operator=(const BinarySearchTree &other);
  BinarySearchTree(const BinarySearchTree &other);
  ~BinarySearchTree();

  void insert(int data);
  void print();

  void setRoot(TreeNode *root);
  TreeNode *getRoot() const;
  int getHeight() const;

private:
  TreeNode *insertNode(TreeNode *root, TreeNode *node); // root is a root of A tree, not THE tree necessarily
  void inorderTraversal(TreeNode *node);
  TreeNode *root_;
  int getHeight(TreeNode *node) const;
};

#endif