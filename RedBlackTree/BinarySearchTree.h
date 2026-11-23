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
  BinarySearchTree(const BinarySearchTree &other);
  ~BinarySearchTree();

  virtual void insert(int data);
  void print();
  void setRoot(TreeNode *root);
  TreeNode *getRoot() const;
  int getHeight() const;
  void deleteNode(int data);
  void inorderTraversal(TreeNode *node);

private:
  TreeNode *insertNode(TreeNode *root, TreeNode *node); // root is a root of A tree, not THE tree necessarily
  TreeNode *root_;
  int getHeight(TreeNode *node) const;
  TreeNode *deleteTreeNode(TreeNode *root, int data);
};

#endif