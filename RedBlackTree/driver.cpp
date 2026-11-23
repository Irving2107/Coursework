// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

// Bst

// If (root != nullptr)
// {
// Root_ =  bst.root_;
// }

// Treenode

// If (tn.getleftchild*() != nullptr)
// {
// Leftchild_ = tn.getleftchild();
// }
// recursive^^^

// override or simply insert node? Deal with later...
// check if it is possible to recolor before anything else. Essentially. push blackness down.
// max nodes for recoloring is 2, parent and uncle.
// if skewed to right, perform a left rotation, and vice versa.
// if full tree rotation, or rotation in general, it is easier to switch data rather than move nodes around.
// swap data not nodes

// insert()
// {
//   inserttreenode()
//   balanceColor()
//   root_setcolor(black)
// }

#include <fstream>
#include "RedBlackTree.h"

int main()
{
  std::ifstream file("data.txt");
  if (!file.is_open())
  {
    std::cerr << "Error: Could not open file." << std::endl;
    return 1;
  }

  RedBlackTree *tree = new RedBlackTree();
  int n;

  // std::cout << "Numbers being inserted: " << std::endl;
  //  inputs file number into tree
  while (file >> n)
  {
    // std::cout << n << " ";
    tree->insert(n);
  }
  // std::cout << std::endl;

  file.close();

  tree->print();

  if (tree->getRoot() != nullptr)
  {
    std::cout << "Root: " << tree->getRoot()->getValue() << std::endl;

    if (tree->getRoot()->getColor() == BLACK)
    {
      std::cout << "Color: BLACK" << std::endl;
    }
    else
    {
      std::cout << "Color: RED" << std::endl;
    }
  }

  // copy constructor test
  RedBlackTree *copyTree = new RedBlackTree(*tree);
  copyTree->print();

  // // get root
  // std::cout << "Root of original tree: " << tree->getRoot()->getValue() << std::endl;
  // // get height
  // std::cout << "Height of original tree: " << tree->getHeight() << std::endl;
  // // modified tree
  copyTree->insert(999);
  copyTree->print();

  delete tree;
  delete copyTree;
  return 0;
}