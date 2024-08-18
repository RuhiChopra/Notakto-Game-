# Notakto Game Project

## Overview
This project involves implementing the game **Notakto**, a two-player game played on two 3x3 boards using the C programming language. The objective is to develop a program that allows either two human players or one human player against the computer to play the game according to the specified rules.

## Game Rules
1. **Game Setup:**
   - There are two 3x3 game boards, both initially empty.
   
2. **Gameplay:**
   - Two players take turns choosing a board and placing a cross (X) on an empty cell.
   - A board is considered dead when it has three consecutive crosses in a row (horizontally, vertically, or diagonally).
   - Players cannot place a cross on a dead board.
   - Players must take turns and cannot skip their turn.
   - The player who places the last cross, making the only remaining non-dead board dead, loses the game. The other player wins.

## Project Requirements
- Implement the game in C with a focus on:
  - Initializing the game boards.
  - Reading the number of players.
  - Displaying the game boards.
  - Handling player and computer moves.
  - Checking for game-ending conditions.
- **Constraints:**
  - No header files other than `stdio.h` are allowed.
  - No global variables are allowed.

## Implementation Details
1. **Functions to Implement:**
   - `initGameBoard()`: Initialize the game boards.
   - `printGameBoard()`: Display the current state of a game board.
   - `isGameBoardDead()`: Check if a game board is dead.
   - `placeCrossByHumanPlayer()`: Handle a move by a human player.
   - `updateGameBoard()`: Update the game board after a move.
   - `placeCrossByComputerPlayer()`: Handle a move by the computer.

2. **Program Flow:**
   - The program starts by initializing the game boards.
   - It then prompts the user to choose the number of players (1 or 2).
   - The game proceeds in turns, with players selecting boards and cells to place crosses.
   - The game continues until one player loses by making the last non-dead board dead.

3. **Computer Player Strategy:**
   - The computer follows a specific strategy for choosing boards and placing crosses, prioritizing moves that either minimize its risk of losing or force the opponent to lose.
