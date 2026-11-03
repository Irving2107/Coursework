// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "DawgHop.h"
int main()
{
  std::ifstream inputFile("deck.txt");

  if (!inputFile.is_open())
  {
    std::cerr << "Error: Could not open deck.txt" << std::endl;
    return 1;
  }

  int numCards;
  inputFile >> numCards;

  DoubleLinkedList *dll = new DoubleLinkedList();

  for (int i = 0; i < numCards; i++)
  {
    int suitValue;
    int faceValue;

    if (!(inputFile >> suitValue >> faceValue))
    {
      std::cerr << "Error: Invalid card data in file" << std::endl;
      return 1;
    }

    Card newCard(suitValue, faceValue);
    dll->insert(newCard);
  }

  inputFile.close();

  std::cout << "Cards from file:" << std::endl;
  dll->printList();

  DawgHop myDawgHop;
  int dawgHops = 0;

  std::cout << "Insertion Sort..." << std::endl;

  myDawgHop.insertionSort(dll, dawgHops);

  dll->printList();

  std::cout << "Dawg Hops: " << dawgHops << std::endl;

  std::cout << "Before deletion of card: " << std::endl;
  dll->printList();
  dll->deleteNode(Card(1, 8)); // deletion of 8 of Spades
  std::cout << "After deletion of card: " << std::endl;
  dll->printList();
  dll->deleteNode(Card(1, 8)); // should return error message
  dll->printList();
  delete dll;

  return 0;
}