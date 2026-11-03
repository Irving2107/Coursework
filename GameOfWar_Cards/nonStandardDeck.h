// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco
#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H
#include "deck.h"

class NonStandardDeck : public Deck
{
public:
  NonStandardDeck();
  ~NonStandardDeck();
  bool isEmpty();                                // override;
  int getNumCards();                             // override;
  void displayCard(int i);                       // override;
  void printDeck();                              // override;
  bool addCard(Card c);                          // override;
  void shuffle();                                // override;
  bool mergeDecks(Deck &, bool shuffle = false); // override;
  void initializeDeck();                         // override;
  Card dealCard();                               // override;

private:
  int inputCards_; // Stores the number of Cards currently in the deck.
  int capacity_;   // Stores the maximum number of Cards that can be stored in the deck.
};

#endif // NON_STANDARD_DECK_H