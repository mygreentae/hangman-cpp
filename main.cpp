#include "hangman.h"

int main()
{
  try
  {

    int gameType = -1;
    std::cout << "Hello! Welcome to Hangman!" << std::endl
              << std::endl;
    std::cout << "Game Types: [1]: words [2]: phrases [3] words and phrases" << std::endl;

    while (true)
    {
      std::cout << "Enter Game Type (1-3): ";
      std::cin >> gameType;

      // make sure the user enters an integer
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
      }
      else
      { // make sure the user enters a number 1-3
        if (gameType > 3 || gameType <= 0)
        {
          std::cout << "Please enter an option between 1 and 3." << std::endl;
        }
        else
        {
          break;
        }
      }
    }

    Hangman game(gameType);
    char letter;
    // remove later (for debugging perposes)
    // std::cout << "Random Word: " << game.getAnswer() << std::endl;

    while (!game.isOver())
    {
      game.display();
      std::cout << "Enter letter (a-z): ";
      std::cin >> letter;

      if (std::cin.fail() || std::cin.peek() != '\n')
      {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a single letter (a-z)." << std::endl;
      }
      else if (!std::isalpha(letter))
      {
        // Check if the character is a letter and is in lower case
        std::cout << "Invalid input. Please enter a single letter (a-z)." << std::endl;
      }
      else
      {
        game.play(std::tolower(letter));
      }
    }

    game.display();

    game.isWon() ? std::cout << "You win! Good game!" : std::cout << "You lose! The word was: " << game.getAnswer();

    std::cout << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}