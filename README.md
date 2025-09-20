# Tic Tac Toe in C

**Classic Tic Tac Toe – Terminal-Based Game in C**

This is a simple yet fully functional Tic Tac Toe game implemented in C. It can be played by **1 player against the computer** or **2 players on the same terminal**. The game demonstrates fundamental programming concepts such as arrays, functions, control flow, and user input handling.

---

## Project Structure

The code is organized professionally into **multiple files**:

- `main.c` – Contains the game loop and overall program flow.  
- `tic_tac_toe.c` – Implements all the game logic: player moves, computer moves, board printing, and winner checking.  
- `tic_tac_toe.h` – Header file with **function declarations** for clean modularity.

---

## About the Game

- **1 or 2 Player Mode:** Play against a friend or challenge the computer.  
- **Computer AI:** The computer makes intelligent moves, blocking potential wins and aiming to win when possible.  
- **Game Board:** The board updates after each move, clearly displaying X’s and O’s.  
- **Input Validation:** Prevents invalid moves and prompts the player to try again if necessary.  

This project reflects my ability to write **clean, modular, and maintainable C code**, using separate header and source files (`tic_tac_toe.h` and `tic_tac_toe.c`) and managing global game state effectively.

---

## How to Play

1. Compile the game using GCC:
   gcc main.c tic_tac_toe.c -o tic_tac_toe
   ./tic_tac_toe   
2. Follow the prompts to:
    Enter the number of players (1 or 2).
    Choose the row and column to place your mark (X or O).
    Try to get three in a row before your opponent or the computer does.

## Future Improvements

I plan to enhance this game in future versions to make it more **challenging, interactive, and maintainable**:

- **Scoreboard:** Track wins, losses, and draws across multiple games.  
- **Enhanced User Interface:** Improve formatting, add colors, or develop a simple GUI.  
- **Save/Load Game:** Allow players to save their progress and continue later.   
- **Extra Features:** Add options for larger board sizes or alternative game modes.  


---

## Key Learnings

- Writing modular C code with separate `.c` and `.h` files.  
- Managing game state using arrays and global variables responsibly.  
- Handling user input robustly to prevent invalid moves.  
- Implementing simple AI logic and decision-making.

## About Me
Hey, I'm Nare! I'm currently a 2nd-year Computer Science student and a lifelong learner.  
C and C++ are my favorite languages to explore and play with. 
I'm curious, hardworking, and always looking for new challenges that make me say "Yes, I did it!"
