// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H
#include "deck.h"
#define DECK_SIZE 52
/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 *
 */
class StandardDeck : public Deck
{
public:
  /// Default constructor.
  StandardDeck();
  /// Default destructor.
  ~StandardDeck();
  /**
   * Returns True/False (1/0) whether or not the Deck is empty.
   *
   * @return Boolean
   */
  bool isEmpty();
  /**
   * Returns the number of cards remaining in the deck.
   *
   * @return Integer value
   */
  int getNumCards();
  /**
   * Displays the i'th card in the Deck.
   *
   * @param[in] Index
   */
  void displayCard(int i);
  /**
   * Prints the contents of the Deck. This method should call the
   * print() method on each Card.
   */
  void printDeck();
  // Method will return true if the card was successfully added to the end of the deck, otherwise it returns false.
  bool addCard(Card c);
  // Method will shuffle the deck of cards.
  void shuffle();
  // Method will merge cards from an input StandardDeck with the current StandardDeck.
  bool mergeDecks(Deck &, bool shuffle = false);
  // Method populates StandardDeck Card array with appropriate 52 cards
  void initializeDeck();
  // Method returns the top most card on the deck
  Card dealCard();
};
#endif
