// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef TREENODE_H
#define TREENODE_H

#include "Node.h"

enum Color
{
  RED,
  BLACK
};

class TreeNode : public Node
{
public:
  TreeNode();
  TreeNode(int data);
  TreeNode(const TreeNode &other);
  ~TreeNode();

  void setLeftChild(TreeNode *leftChild);
  void setRightChild(TreeNode *rightChild);
  void setParent(TreeNode *parent);

  TreeNode *getLeftChild() const;
  TreeNode *getRightChild() const;
  TreeNode *getParent() const;

  void setColor(Color color);
  Color getColor() const;

private:
  TreeNode *leftChild_;
  TreeNode *rightChild_;
  TreeNode *parent_;
  Color color_;
};
#endif