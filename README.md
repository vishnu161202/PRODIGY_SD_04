# PRODIGY_SD_04
## Implement a Sudoku Solver

## Problem Statement:
Create a program that solves Sudoku puzzles automatically. The program should take an input grid representing an unsolved Sudoku puzzle and use an algorithm to fill in the missing numbers.
It should use backtracking or other suitable techniques to explore possible solutions and find the correct arrangement of numbers for the puzzle. Once solved, the program should display the completed Sudoku grid.


## Solution:
### Data Structures:
Defines a constant N representing the size of the Sudoku grid (9x9 in this case).
Uses a 2D array grid[N][N] to represent the Sudoku puzzle.

### Helper Functions:
isSafe(): Checks if it's safe to place a number num at a specific position (row, col) in the grid based on Sudoku rules (no duplicate numbers in the same row, column, or 3x3 subgrid).
solveSudoku(): Recursively solves the Sudoku puzzle by backtracking. It finds an empty cell, tries placing numbers, and continues until a solution is found or determines that no solution exists.

### Main Function:
Takes input for the initial Sudoku grid from the user, where 0 represents empty cells.
Calls the solveSudoku() function to solve the puzzle.
If a solution is found, it prints the solved Sudoku grid using the printGrid() function; otherwise, it indicates that no solution exists.

### Printing Function:
printGrid(): Prints the Sudoku grid to the console.
