#include <iostream>
using namespace std;

// Size of the Sudoku grid
const int N = 9;

// Helper function to check if a number can be placed at a specific position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not already present in the current row, column, or 3x3 subgrid
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[subgridStartRow + i][subgridStartCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell (cell with 0 value)
    bool isEmpty = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If no empty cell is found, the Sudoku puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recur to solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing num at (row, col) doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No number can be placed at (row, col) to solve the puzzle
    return false;
}

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N];

    cout << "Enter the Sudoku grid (0 for empty cells, separated by spaces):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "\nSudoku Solved:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
