// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

// phase 2 from notes
// override or simply insert node? Deal with later...
// node class, and treenode class. linkednode class not needed.
// will be adding a delete functionality, eventually.
// check if it is possible to recolor before anything else. Essentially, push the blackness down.
// max nodes for recoloring is 2, parent and uncle.
// if skewed to right, perform a left rotation, and vice versa.
// if full tree rotation, or rotation in general, it is easier to switch data rather than move nodes around.
#include <fstream>
#include "BinarySearchTree.h"

int main()
{
  std::ifstream file("data.txt");
  if (!file.is_open())
  {
    std::cerr << "Error: Could not open file." << std::endl;
    return 1;
  }

  BinarySearchTree *tree = new BinarySearchTree();
  int n;

  std::cout << "Numbers being inserted: " << std::endl;
  // inputs file number into tree
  while (file >> n)
  {
    std::cout << n << " ";
    tree->insert(n);
  }
  std::cout << std::endl;

  file.close();

  tree->print();

  // copy constructor test
  BinarySearchTree *copyTree = new BinarySearchTree(*tree);
  copyTree->print();

  // get root
  std::cout << "Root of original tree: " << tree->getRoot()->getValue() << std::endl;
  // get height
  std::cout << "Height of original tree: " << tree->getHeight() << std::endl;
  // modified tree
  copyTree->insert(999);
  copyTree->print();

  delete tree;
  delete copyTree;
  return 0;
}