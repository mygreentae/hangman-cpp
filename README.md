# Welcome to Hangman!

Hangman is a classic word-guessing game implemented in C++. Try to guess the word or phrase one letter at a time before you run out of attempts!

## Features
- Choose between guessing words, phrases, or both.
- Customizable word and phrase lists.
- Simple and fun command-line interface.

## Installation

To install hangman.cpp please clone this repo!

```
$ git clone https://github.com/mygreentae/hangman-cpp.git
```

Then use `make` to install.

```
$ cd hangman-cpp
$ make
$ ./hangman
```

## Gameplay

When launching the game, you will be prompted:

```
Hello! Welcome to Hangman!

Game Types: [1]: words [2]: phrases [3] words and phrases
Enter Game Type (1-3):
```

You can enter the game type you would like to play. 

### Rules

- You will be presented with a series of blanks representing the letters in the word or phrase.
- Guess one letter at a time.
- Each incorrect guess adds a part to the hangman figure.
- The game ends when you either guess the word/phrase correctly or the hangman figure is fully drawn.

### Controls

- Enter a single letter to guess.
- You can view the current state of the word or phrase after each guess.
- Keep track of your incorrect guesses.

### Example Game

```
Hello! Welcome to Hangman!

Game Types: [1]: words [2]: phrases [3] words and phrases
Enter Game Type (1-3): 1
 
  +---+
  |   |
      |
      |
      |
      |
=========

_ _ _ 

Enter letter (a-z): e
 
  +---+
  |   |
      |
      |
      |
      |
=========

_ _ e 

Enter letter (a-z): a
 
  +---+
  |   |
  O   |
      |
      |
      |
=========

Letters guessed (incorrect): a 

_ _ e 

Enter letter (a-z): c
 
  +---+
  |   |
  O   |
  |   |
      |
      |
=========

Letters guessed (incorrect): a c 

_ _ e 

Enter letter (a-z): w
 
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========

Letters guessed (incorrect): a c w 

_ _ e 

Enter letter (a-z): y
 
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========

Letters guessed (incorrect): a c w y 

_ _ e 

Enter letter (a-z): v
 
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========

Letters guessed (incorrect): a c w y v 

_ _ e 

Enter letter (a-z): d
 
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========

Letters guessed (incorrect): a c w y v d 

_ _ e 

You lose! The word was: lie
```

## Customization

You can customize the word and phrase lists by modifying the dictionary files in `./dictionaries` in the repository. Ensure each word or phrase is on a new line.

## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request with your changes.

## Contact

For any questions or feedback, please contact me.