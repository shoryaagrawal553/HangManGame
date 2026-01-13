# 🎯 Hangman Game in C++

## 🕹️ Overview

**Hangman Game** is a console-based word-guessing game implemented in **C++**.
The player must correctly guess a randomly selected **fruit name** within a limited number of attempts before the hangman drawing is completed.

This project is designed for **beginner to intermediate C++ learners** and demonstrates core programming concepts such as **object-oriented design**, **standard library usage**, **random number generation**, and **input validation**, all presented with simple ASCII-based visuals.

---

## ✨ Features

* 🎲 Random fruit selection from a predefined list
* 🔤 Letter-by-letter guessing with input validation
* 🧠 Tracks previously guessed letters to prevent duplicates
* ❌ Limited attempts with visual hangman progression
* 🖥️ Fully console-based and cross-platform
* 📘 Beginner-friendly, clean, and well-structured C++ code

---

## 🧩 How the Game Works

1. The program randomly selects a **fruit name**.
2. The word is hidden using underscores (`_`).
3. The player guesses one letter per turn.
4. Correct guesses reveal the letter in the word.
5. Incorrect guesses reduce the remaining attempts and update the hangman drawing.
6. The game ends when:

   * The word is fully guessed (**Win**), or
   * All attempts are exhausted (**Loss**).

---

## 💻 Sample Gameplay

```
Welcome to Hangman!
Category: Fruits
You have 6 attempts to guess the fruit name.

Word: _____
Attempts left: 6
Guessed letters: 

Guess a letter: a
Good guess!

Word: a___a
Attempts left: 6
Guessed letters: a

Guess a letter: p
Incorrect guess.

 _____
 |
 O

Word: a___a
Attempts left: 5
Guessed letters: a p
```

---

## 🧠 Concepts Demonstrated

### 🔹 Object-Oriented Programming (OOP)

* Encapsulation of game logic within classes
* Improved readability and maintainability

### 🔹 Standard Template Library (STL)

* `vector` for word storage
* `string` for text manipulation
* `algorithm` utilities where applicable

### 🔹 Randomization

* `rand()` and `srand()` for selecting random words

### 🔹 Input Handling & Validation

* Ensures valid alphabetical input
* Converts input to lowercase
* Prevents repeated guesses

### 🔹 Control Flow

* Loops and conditionals manage gameplay and state transitions

---

## 🏗️ Project Structure

```
📂 Hangman-Game/
 ├── hangman.cpp       # Main source file containing game logic
 └── README.md         # Project documentation
```

---

## 🚀 Getting Started

### 💻 Compile and Run (g++)

```bash
g++ hangman.cpp -o hangman
./hangman
```

### 🪟 Run Using Visual Studio Code

1. Open the project folder in **VS Code**
2. Install the **C/C++ extension**
3. Build the project using **Ctrl + Shift + B**
4. Run the program using **F5**

---

## 🧰 Requirements

* C++11 or higher
* Any standard C++ compiler:

  * `g++`
  * `clang`
  * MSVC (Visual Studio)

---

## 🌱 Future Improvements

* Difficulty levels (Easy / Medium / Hard)
* Multiple categories (Fruits, Animals, Countries, etc.)
* Score tracking and high-score system
* Improved ASCII graphics
* Graphical version using **SFML** or **SDL**

---

## 📄 License

This project is licensed under the **MIT License** and is free to use, modify, and distribute.
