#include "hangman.h"

// Hangman::Hangman() {
//     gameOver = false;
//     gameWon = false;
//     incorrectTry = 0;
//     lettersGuessed = {};
//     hangmanPics = {  
//         R"( 
//   +---+
//   |   |
//       |
//       |
//       |
//       |
// =========
// )",
//         R"( 
//   +---+
//   |   |
//   O   |
//       |
//       |
//       |
// =========
// )",
//         R"( 
//   +---+
//   |   |
//   O   |
//   |   |
//       |
//       |
// =========
// )",
//         R"( 
//   +---+
//   |   |
//   O   |
//  /|   |
//       |
//       |
// =========
// )",
//         R"( 
//   +---+
//   |   |
//   O   |
//  /|\  |
//       |
//       |
// =========
// )",
//         R"( 
//   +---+
//   |   |
//   O   |
//  /|\  |
//  /    |
//       |
// =========
// )",
//         R"( 
//   +---+
//   |   |
//   O   |
//  /|\  |
//  / \  |
//       |
// =========
// )"
//     };

//     // choose random word 
//     std::ifstream file("dictionaries/5-letter-words.txt");
//     if (!file.is_open()) {
//         throw std::runtime_error("Error: Could not open dictionary.") ;
//     }

//     std::vector<std::string> lines;
//     std::string line;

//     while(std::getline(file, line)) {
//         lines.push_back(line);
//     }

//     if (lines.empty()) {
//         throw std::runtime_error("Error: The dictionary is empty!");
//     }

//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> distr(0, lines.size() - 1);

//     int randomIndex = distr(gen);

//     answer = lines[randomIndex];
//     answerSize = answer.size();
//     guessState = std::vector<char>(answerSize, '_');
    
// }

Hangman::Hangman(const int gameType) {
    gameOver = false;
    gameWon = false;
    incorrectTry = 0;
    lettersGuessed = {};
    hangmanPics = {  
        R"( 
  +---+
  |   |
      |
      |
      |
      |
=========
)",
        R"( 
  +---+
  |   |
  O   |
      |
      |
      |
=========
)",
        R"( 
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)",
        R"( 
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)",
        R"( 
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)",
        R"( 
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)",
        R"( 
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)"
    };



    // choose random word 
    std::vector<std::string> gameTypes = {"words", "phrases", "words-and-phrases"};
    std::ifstream file("dictionaries/"+gameTypes[gameType-1]+".txt");
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open dictionary.") ;
    }

    std::vector<std::string> lines;
    std::string line;

    while(std::getline(file, line)) {
        lines.push_back(line);
    }

    if (lines.empty()) {
        throw std::runtime_error("Error: The dictionary is empty!");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, lines.size() - 1);

    int randomIndex = distr(gen);

    answer = lines[randomIndex];
    answerSize = answer.size();
    for (char ch : answer) {
        if (ch == ' ') {
            guessState.push_back(' '); // Preserve spaces
        } else {
            guessState.push_back('_'); // Hide letters
        }
    }
}

std::string Hangman::getAnswer() {
    return answer;
}

void Hangman::display() const {
    std::cout << hangmanPics[incorrectTry] << std::endl;
    if (lettersGuessed.size() > 0) {
        std::cout << "Letters guessed (incorrect): ";
        for (char letter : lettersGuessed) {
            std::cout << letter << " ";
        }
        std::cout << std::endl << std::endl;
    }

    for (char letter : guessState) {
        std::cout << letter << " ";
    }
    std::cout << std::endl << std::endl;
}

bool Hangman::isWon() const {
    return gameWon;
}

bool Hangman::isOver() const {
    return gameOver;
}

void Hangman::play(char letter) {
    bool found = false;
    for (int i = 0; i < answerSize; ++i) {
        if (std::tolower(answer[i]) == letter) {
            guessState[i] = letter;
            found = true;
        }
    }
    // see if game is over
    if (!found) {
        if (std::find(lettersGuessed.begin(), lettersGuessed.end(), letter) == 
            lettersGuessed.end()) {
            ++incorrectTry;
            lettersGuessed.push_back(letter);
        }
        if (incorrectTry == hangmanPics.size()-1) {
            gameOver = true;
        }
    }
    // see if game is won
    gameWon = std::find(guessState.begin(), guessState.end(), '_') == guessState.end();
    gameOver = gameOver || gameWon;
}