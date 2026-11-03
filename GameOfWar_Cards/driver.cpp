// Honor Pledge : I pledge that I have neither given nor received any help on this assignment.
// iluisorozco

#include "standardDeck.h"
#include "nonStandardDeck.h"

int main()
{
  int points[2] = {0, 0};
  int winScore[2] = {0, 0};

  srand(time(nullptr));

  for (int j = 0; j < 50; j++)
  {
    int currentPlayer = 0;
    bool hasPreviousCard = false;
    Card previousCard;
    Card currentCard;

    Deck *players[2];
    players[0] = new StandardDeck();
    players[1] = new StandardDeck();
    Deck *battleground = new NonStandardDeck();

    battleground->initializeDeck();
    battleground->shuffle();

    // Deal the cards between the two players
    while (!battleground->isEmpty())
    {
      players[0]->addCard(battleground->dealCard());

      if (!battleground->isEmpty())
      {
        players[1]->addCard(battleground->dealCard());
      }
    }

    // Play the game
    while (!players[0]->isEmpty() && !players[1]->isEmpty())
    {
      // Current player plays a card
      currentCard = players[currentPlayer]->dealCard();

      battleground->addCard(currentCard);

      // Check for a matching face
      if (hasPreviousCard &&
          currentCard.getFace() == previousCard.getFace())
      {
        // Current player wins the battleground
        players[currentPlayer]->mergeDecks(*battleground, true);

        hasPreviousCard = false;
      }
      else
      {
        previousCard = currentCard;
        hasPreviousCard = true;

        // Switch players
        currentPlayer = 1 - currentPlayer;
      }
    }

    // Determine the winner
    if (players[0]->isEmpty())
    {
      points[1]++;
      winScore[1] += players[1]->getNumCards();
    }
    else if (players[1]->isEmpty())
    {
      points[0]++;
      winScore[0] += players[0]->getNumCards();
    }

    delete players[0];
    delete players[1];
    delete battleground;
  }

  // Determine the champion
  if (points[0] > points[1])
  {
    std::cout << "Player 1 was the champion with "
              << points[0]
              << " victories versus Player 2."
              << std::endl;
  }
  else if (points[1] > points[0])
  {
    std::cout << "Player 2 was the champion with "
              << points[1]
              << " victories versus Player 1."
              << std::endl;
  }
  else
  {
    std::cout << "Both players had equal wins"
              << std::endl;
  }

  // Player 1 average
  if (points[0] > 0)
  {
    std::cout << "Player 1 Average Score: "
              << static_cast<double>(winScore[0]) / points[0]
              << std::endl;
  }
  else
  {
    std::cout << "Player 1 had no victories."
              << std::endl;
  }

  // Player 2 average
  if (points[1] > 0)
  {
    std::cout << "Player 2 Average Score: "
              << static_cast<double>(winScore[1]) / points[1]
              << std::endl;
  }
  else
  {
    std::cout << "Player 2 had no victories."
              << std::endl;
  }

  return 0;
}