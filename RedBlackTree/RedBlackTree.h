// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
public:
  RedBlackTree();
  RedBlackTree(const RedBlackTree &other);
  virtual ~RedBlackTree();
  virtual void insert(int data);

private:
  void rotateLeft(TreeNode *&root, TreeNode *&newNode);
  void rotateRight(TreeNode *&root, TreeNode *&newNode);
  void balanceColor(TreeNode *&root, TreeNode *&newNode);
};
#endif