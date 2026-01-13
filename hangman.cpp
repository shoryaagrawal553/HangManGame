// C++ program to implement the Hangman game
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
// Define the maximum number of incorrect attempts allowed
#define MAX_ATTEMPTS 6
using namespace std;
// HangmanGame class definition
class HangmanGame{
public:
    // Constructor to initialize game variables
    HangmanGame() {
        
        srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator
        secretWord = getRandomWord(); // Select a random word from the predefined list
        currentWord = string(secretWord.length(), '_'); // Initialize the hidden word with underscores
        attemptsLeft = MAX_ATTEMPTS; // Set the number of attempts
    }

    // Function to start and control the game flow
    void play()
    {
        cout << "Welcome to Hangman!" << endl;
        cout << "Category: Fruits" << endl;
        cout << "You have " << attemptsLeft << " attempts to guess the fruit name." << endl;

        // Main game loop: continues until attempts are exhausted or the word is guessed
        while (attemptsLeft > 0)
        {
            displayGameInfo(); // Show the current game state
            char guess;
            cout << "Guess a letter: ";
            cin >> guess;

            // Check if the input is a valid alphabetic character
            if (isalpha(guess))
            {
                guess = tolower(guess); // Convert to lowercase for consistency

                // Check if the letter was already guessed
                if (alreadyGuessed(guess))
                {
                    cout << "You've already guessed that letter." << endl;
                }
                else
                {
                    // Check if the guessed letter is in the secret word
                    bool correctGuess = updateCurrentWord(guess);

                    if (correctGuess)
                    {
                        cout << "Good guess!" << endl;
                        // Check if the entire word has been guessed
                        if (currentWord == secretWord)
                        {
                            displayGameInfo();
                            cout << "Congratulations! You guessed the word: " << secretWord << endl;
                            return; // End the game if guessed correctly
                        }
                    }
                    else
                    {
                        cout << "Incorrect guess." << endl;
                        attemptsLeft--; // Reduce attempts for incorrect guesses
                        drawHangman(attemptsLeft); // Display hangman progress
                    }
                }
            }
            else
            {
                cout << "Please enter a valid letter." << endl;
            }
        }

        // If no attempts are left, reveal the correct word
        if (attemptsLeft == 0)
        {
            displayGameInfo();
            cout << "You've run out of attempts. The word was: " << secretWord << endl;
        }
    }

private:
    string secretWord;   // The word to be guessed
    string currentWord;  // The word with guessed letters filled in
    int attemptsLeft;    // Number of remaining incorrect guesses
    vector<char> guessedLetters; // Stores guessed letters

    // Function to randomly select a word from a predefined list
    string getRandomWord()
    {
        vector<string> words = {"apple", "banana", "mango", "orange", "papaya",
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
                                "acerola", "longan", "loquat", "breadfruit"};
        
        int index = rand() % words.size(); // Generate a random index
        return words[index]; // Return a randomly selected word
    }

    // Function to check if a letter has already been guessed
    bool alreadyGuessed(char letter)
    {
        return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
    }

    // Function to update the current word with a correct guess
    bool updateCurrentWord(char letter)
    {
        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); i++)
        {
            if (secretWord[i] == letter)
            {
                currentWord[i] = letter; // Reveal the guessed letter
                correctGuess = true;
            }
        }
        guessedLetters.push_back(letter); // Add letter to guessed letters list
        return correctGuess;
    }

    // Function to display the current game state
    void displayGameInfo()
    {
        cout << "Word: " << currentWord << endl;
        cout << "Attempts left: " << attemptsLeft << endl;
        cout << "Guessed letters: ";
        for (char letter : guessedLetters)
        {
            cout << letter << " ";
        }
        cout << endl;
    }

    // Function to progressively draw the hangman based on incorrect attempts
    void drawHangman(int attemptsLeft){
        // Simple ASCII art for different stages of the hangman
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

// Driver function to start the game
int main(){
    HangmanGame game; // Create an instance of HangmanGame
    game.play(); // Start the game
    return 0;
}




