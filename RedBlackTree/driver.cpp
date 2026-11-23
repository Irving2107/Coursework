// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

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

  while (file >> n)
  {
    tree->insert(n);
  }

  file.close();

  std::cout << "Red Nodes: ";
  tree->printRedNodes(tree->getRoot());
  std::cout << std::endl;

  std::cout << "Black Nodes: ";
  tree->printBlackNodes(tree->getRoot());
  std::cout << std::endl;

  if (tree->getRoot() != nullptr)
  {
    std::cout << "Root: " << tree->getRoot()->getValue() << std::endl;
  }

  delete tree;
  return 0;
}