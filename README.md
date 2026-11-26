# 🎮 Number Quest – Guess the Secret Number

A console-based number guessing game developed in **C Programming** as part of the FOCP-I (Fundamentals of Computer Programming-I) Mini Project at The NorthCap University.

The game challenges players to guess a randomly generated secret number within a limited number of attempts. Players receive hints after every guess to help them find the correct number.

## 📌 Project Information

| Detail               | Description             |
| -------------------- | ----------------------- |
| Project Name         | Number Quest            |
| Project Type         | Console-Based Game      |
| Programming Language | C                       |
| Course               | FOCP-I                  |
| University           | The NorthCap University |
| Difficulty           | Beginner                |

## 🎯 Features

- **Three Difficulty Levels**
  - Easy: Numbers from 1–50 (10 attempts)
  - Medium: Numbers from 1–100 (7 attempts)
  - Hard: Numbers from 1–200 (6 attempts)
- Random secret number generation.
- Higher and lower hints after every guess.
- Limited attempts for each difficulty.
- Score calculation based on remaining attempts and difficulty bonus.
- Input validation to prevent invalid entries.
- Instructions and main menu.
- Win and game-over messages.

## 🛠️ Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code
- Git and GitHub

## 📂 Project Structure

``text
Project_Number_Quest/
│
├── Game.c
├── README.md
│
├── screenshots/
│   ├── menu.png
│   ├── gameplay.png
│   └── result.png
│
└── docs/
    └── Project_Documentation.pdf
```

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/Nashu07/Project_Number_Quest.git
```

### 2. Navigate to the Project Folder

```bash
cd Project_Number_Quest
```

### 3. Compile the Program

Using GCC:

```bash
gcc -Wall -Wextra -std=c11 Game.c -o Game
```

### 4. Run the Game

**Windows:**

```powershell
.\Game.exe
```

**Linux:**

```bash
./Game
```

## 🎮 How to Play

1. Launch the program.
2. Select Start Game from the main menu.
3. Choose your preferred difficulty level.
4. Enter a number within the displayed range.
5. Follow the higher or lower hints.
6. Guess the secret number before running out of attempts.
7. Your final score will be displayed.

## 📸 Screenshots

Screenshots of the game interface will be added here.

| Main Menu  | Gameplay       | Final Result |
| ---------- | -------------- | ------------ |
| `menu.png` | `gameplay.png` | `result.png` |

## 📚 C Programming Concepts Used

- Variables and data types
- Conditional statements (`if-else`, `switch`)
- Loops (`while`, `do-while`)
- User-defined functions
- Function parameters and pointers
- Random number generation (`rand()`, `srand()`)
- Input handling (`fgets()`, `strtol()`)
- Header files and standard libraries

## 👥 Team Members

1. Nashir Ali
2. Chandan Singh
3. Kush Agarwal
4. Sagar
5. Deepanshu Yadav

## 🎓 Academic Project

This project is developed for the FOCP-I Mini Project submission at **The NorthCap University**.

---

**Made with C | Number Quest**
