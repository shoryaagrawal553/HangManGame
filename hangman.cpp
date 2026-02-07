// C++ program to implement the Hangman game

#include <algorithm>
#include <cctype>
#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

// Define the maximum number of incorrect attempts allowed
static const int MAX_ATTEMPTS = 6;

// HangmanGame class definition
class HangmanGame {
public:
    // Constructor to initialize game variables
    HangmanGame() {
        srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator
        secretWord = getRandomWord();                     // Select a random word
        currentWord = string(secretWord.length(), '_');   // Initialize hidden word
        attemptsLeft = MAX_ATTEMPTS;                      // Set attempts
    }

    // Function to start and control the game flow
    void play() {
        cout << "Welcome to Hangman!\n";
        cout << "Category: Fruits\n";
        cout << "You have " << attemptsLeft
             << " attempts to guess the fruit name.\n";

        // Main game loop
        while (attemptsLeft > 0) {
            displayGameInfo();

            char guess;
            cout << "Guess a letter: ";
            cin >> guess;

            // Validate input
            if (!isalpha(guess)) {
                cout << "Please enter a valid letter.\n";
                continue;
            }

            guess = static_cast<char>(tolower(guess));

            if (alreadyGuessed(guess)) {
                cout << "You've already guessed that letter.\n";
                continue;
            }

            bool correctGuess = updateCurrentWord(guess);

            if (correctGuess) {
                cout << "Good guess!\n";

                if (currentWord == secretWord) {
                    displayGameInfo();
                    cout << "Congratulations! You guessed the word: "
                         << secretWord << "\n";
                    return;
                }
            } else {
                cout << "Incorrect guess.\n";
                attemptsLeft--;
                drawHangman(attemptsLeft);
            }
        }

        // Game over
        displayGameInfo();
        cout << "You've run out of attempts. The word was: "
             << secretWord << "\n";
    }

private:
    string secretWord;
    string currentWord;
    int attemptsLeft;
    vector<char> guessedLetters;

    // Select a random word
    string getRandomWord() {
        const vector<string> words = {
            "apple", "banana", "mango", "orange", "papaya",
            "pineapple", "watermelon", "grapes", "strawberry",
            "blueberry", "raspberry", "cherry", "kiwi",
            "pomegranate", "guava", "peach", "pear", "plum",
            "lychee", "coconut", "lemon", "lime", "fig",
            "apricot", "dragonfruit", "starfruit",
            "passionfruit", "blackcurrant", "gooseberry",
            "mulberry", "custardapple", "jackfruit", "dates",
            "cranberry", "avocado", "persimmon", "tamarind",
            "cantaloupe", "honeydew", "sapodilla", "rambutan",
            "durian", "elderberry", "mangosteen", "bael",
            "acerola", "longan", "loquat", "breadfruit"
        };

        int index = rand() % words.size();
        return words[index];
    }

    // Check if a letter was already guessed
    bool alreadyGuessed(char letter) const {
        return find(guessedLetters.begin(),
                    guessedLetters.end(),
                    letter) != guessedLetters.end();
    }

    // Update word with guessed letter
    bool updateCurrentWord(char letter) {
        bool correctGuess = false;

        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                currentWord[i] = letter;
                correctGuess = true;
            }
        }

        guessedLetters.push_back(letter);
        return correctGuess;
    }

    // Display current game state
    void displayGameInfo() const {
        cout << "Word: " << currentWord << "\n";
        cout << "Attempts left: " << attemptsLeft << "\n";
        cout << "Guessed letters: ";

        for (char letter : guessedLetters) {
            cout << letter << " ";
        }

        cout << "\n";
    }

    // Draw hangman based on remaining attempts
    void drawHangman(int attemptsLeft) const {
        if (attemptsLeft == 5)
        {
            cout << " _____" << endl;
            cout << " |" << endl;
            cout << " O" << endl;
        }
        else if (attemptsLeft == 4)
        {
            cout << " _____" << endl;
            cout << " |" << endl;
            cout << " O" << endl;
            cout << " |" << endl;
        }
        else if (attemptsLeft == 3)
        {
            cout << " _____" << endl;
            cout << " |" << endl;
            cout << " O" << endl;
            cout << "/|" << endl;
        }
        else if (attemptsLeft == 2)
        {
            cout << " _____" << endl;
            cout << " |" << endl;
            cout << " O" << endl;
            cout << "/|\\" << endl;
        }
        else if (attemptsLeft == 1)
        {
            cout << " _____" << endl;
            cout << " |" << endl;
            cout << " O" << endl;
            cout << "/|\\" << endl;
            cout << " /" << endl;
        }
        else if (attemptsLeft == 0)
        {
            cout << " _____" << endl;
            cout << " |" << endl;
            cout << " O" << endl;
            cout << "/|\\" << endl;
            cout << "/ \\" << endl;
        }
    }
};

// Driver function
int main() {
    HangmanGame game;
    game.play();
    return 0;
}
