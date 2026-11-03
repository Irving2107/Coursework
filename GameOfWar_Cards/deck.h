// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck
{
public:
  virtual ~Deck() {};
  virtual bool isEmpty() = 0;
  virtual int getNumCards() = 0;
  virtual void displayCard(int i) = 0;
  virtual void printDeck() = 0;
  virtual bool addCard(Card c) = 0;
  virtual void shuffle() = 0;
  virtual bool mergeDecks(Deck &, bool shuffle = false) = 0;
  virtual void initializeDeck() = 0;
  virtual Card dealCard() = 0;

protected:
  Card *deck_;   // Pointer to record the location of the array of Cards in memory.
  int numCards_; // Stores the number of Cards currently in the deck.
};

#endif