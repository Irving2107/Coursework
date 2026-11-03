// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "standardDeck.h"

StandardDeck::StandardDeck()
{
  deck_ = new Card[DECK_SIZE];
  numCards_ = 0;
}

StandardDeck::~StandardDeck()
{
  if (deck_ != nullptr)
  {
    delete[] deck_;
  }
}

bool StandardDeck::isEmpty()
{
  return numCards_ == 0;
}

int StandardDeck::getNumCards()
{
  return numCards_;
}

void StandardDeck::displayCard(int i)
{
  if (i >= 0 && i < numCards_)
  {
    std::cout << "Card at index " << i << ": " << deck_[i].print() << std::endl;
  }
  else
  {
    std::cout << "Invalid index." << std::endl;
  }
}

void StandardDeck::printDeck()
{
  for (int i = 0; i < numCards_; i++)
  {
    std::cout << deck_[i].print() << std::endl;
  }
}

bool StandardDeck::addCard(Card card)
{
  // The commented lines are not needed for the assignment, but they were useful during testing.
  if (numCards_ < DECK_SIZE)
  {
    deck_[numCards_] = card;
    numCards_++;
    // std::cout << "Card successfully added to the deck." << std::endl;
    return true;
  }
  else
  {
    std::cout << "Deck is full. Cannot add more cards." << std::endl;
  }
  return false;
}

void StandardDeck::shuffle()
{
  for (int i = 0; i < 3 * numCards_; i++)
  {
    int j = rand() % numCards_;
    int k = rand() % numCards_;
    std::swap(deck_[j], deck_[k]);
  }
  // std::cout << "Deck shuffled." << std::endl;
}

bool StandardDeck::mergeDecks(Deck &otherDeck, bool shuffle)
{
  // Since there can't be more than 52 cards in a deck, we must check
  // that the number of cards in both decks do not go past this.
  if (numCards_ + otherDeck.getNumCards() > DECK_SIZE)
  {
    // std::cout << "Card amount out of bounds." << std::endl;
    return false;
  }

  while (!otherDeck.isEmpty())
  {
    addCard(otherDeck.dealCard());
  }

  if (shuffle)
  {
    this->shuffle();
  }
  return true;
}

void StandardDeck::initializeDeck()
{
  for (int i = 0; i < DECK_SIZE; i++)
  {
    deck_[i] = Card(i / 13 + 1, i % 13 + 1);
  }
  numCards_ = DECK_SIZE;
}

Card StandardDeck::dealCard()
{
  if (numCards_ == 0)
  {
    // std::cout << "No card to deal" << std::endl;
    return Card();
  }

  Card card = deck_[numCards_ - 1];
  numCards_--;
  return card;
}