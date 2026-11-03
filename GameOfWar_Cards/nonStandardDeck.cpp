// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#include "nonStandardDeck.h"

NonStandardDeck::NonStandardDeck() : inputCards_(0), capacity_(100)
{
  deck_ = nullptr;
}

NonStandardDeck::~NonStandardDeck()
{
  if (deck_ != nullptr)
  {
    delete[] deck_;
  }
}

bool NonStandardDeck::isEmpty()
{
  return inputCards_ == 0;
}

int NonStandardDeck::getNumCards()
{
  return inputCards_;
}

void NonStandardDeck::displayCard(int i)
{
  if (i >= 0 && i < inputCards_)
  {
    std::cout << "Card at index " << i << ": " << deck_[i].print() << std::endl;
  }
  else
  {
    std::cout << "Invalid index." << std::endl;
  }
}

void NonStandardDeck::printDeck()
{
  for (int i = 0; i < inputCards_; i++)
  {
    std::cout << deck_[i].print() << std::endl;
  }
}

bool NonStandardDeck::addCard(Card c)
{
  if (inputCards_ >= capacity_)
  {
    int newCapacity = capacity_ + 10; // Increase capacity by 10
    Card *newDeck = new Card[newCapacity];
    for (int i = 0; i < inputCards_; i++)
    {
      newDeck[i] = deck_[i];
    }
    delete[] deck_;
    deck_ = newDeck;
    capacity_ = newCapacity;
  }

  deck_[inputCards_] = c;
  inputCards_++;
  return true;
}

void NonStandardDeck::shuffle()
{
  for (int i = 0; i < 3 * inputCards_; i++)
  {
    int j = rand() % inputCards_;
    int k = rand() % inputCards_;
    std::swap(deck_[j], deck_[k]);
  }
}

bool NonStandardDeck::mergeDecks(Deck &otherDeck, bool shuffle)
{
  int otherDeckSize = otherDeck.getNumCards();
  for (int i = 0; i < otherDeckSize; i++)
  {
    Card c = otherDeck.dealCard();
    addCard(c);
  }
  if (shuffle)
  {
    this->shuffle();
  }
  return true;
}

void NonStandardDeck::initializeDeck()
{
  std::ifstream file("deck.txt");
  if (!file)
  {
    std::cerr << "Error: Could not open deck.txt" << std::endl;
    return;
  }

  int deckSize;
  // Reads the first line of the file to get the number of cards in the deck
  file >> deckSize;
  // If deck_ is not null, this deletes the existing array to avoid memory leaks
  if (deck_ != nullptr)
  {
    delete[] deck_;
  }

  deck_ = new Card[deckSize];
  inputCards_ = 0;
  // Reads the cards from the file and runs a loop to initialize the deck
  for (int i = 0; i < deckSize; i++)
  {
    int suit, face;
    file >> suit >> face;
    deck_[i] = Card(suit, face);
    inputCards_++;
  }
  file.close();
}

Card NonStandardDeck::dealCard()
{
  if (inputCards_ > 0)
  {
    Card dealtCard = deck_[inputCards_ - 1];
    inputCards_--;
    return dealtCard;
  }
  else
  {
    std::cerr << "Error: Attempted to deal a card from an empty deck." << std::endl;
    return Card(); // Returns a default-constructed Card in case of error.
  }
}