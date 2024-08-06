#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

class Hangman {
private:
    std::string answer;
    std::vector<std::string> hangmanPics;
    std::vector<char> guessState;
    std::vector<char> lettersGuessed;
    bool gameOver;
    bool gameWon;
    int incorrectTry;
    int answerSize;
public:
    Hangman();
    Hangman(const int gameType);
    std::string getAnswer();
    void display() const;
    bool isWon() const ;
    bool isOver() const;
    void play(char letter);
};

#endif