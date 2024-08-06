#include "hangman.h"

int main() {
  try {
    
    int gameType;
    std::cout << "Hello! Welcome to Hangman!" << std::endl;
    std::cout << "Game Types: [1]: words [2]: phrases [3] words and phrases" << std::endl;
    std::cout << "Enter Game Type: ";
    std::cin >> gameType;
    
    Hangman game(gameType);
    char letter;
    // remove later (for debugging perposes)
    //std::cout << "Random Word: " << game.getAnswer() << std::endl;

    while(!game.isOver()) {
      game.display();
      std::cout << "Enter letter: ";
      std::cin >> letter;
      game.play(std::tolower(letter));
    }

    game.display();

    game.isWon() ? std::cout << "You win! Good game!" : 
      std::cout << "You lose! The word was: " << game.getAnswer();

    std::cout << std::endl;

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}