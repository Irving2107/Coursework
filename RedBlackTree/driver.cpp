// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

// print all values from same line
// phase 2 from notes
// override or simply insert node? Deal with later...
// node class, and treenode class. linkednode class not needed.
// will be adding a delete functionality, eventually.
// check if it is possible to recolor before anything else. Essentially, push the blackness down.
// max nodes for recoloring is 2, parent and uncle.
// if skewed to right, perform a left rotation, and vice versa.
// if full tree rotation, or rotation in general, it is easier to switch data rather than move nodes around.
#include <iostream>
#include <fstream>

int main()
{
  std::ifstream file("data.txt");
  if (!file.is_open())
  {
    std::cerr << "Error: Could not open file." << std::endl;
    return 1;
  }

  int n;

  while (file >> n)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  file.close();

  return 0;
}