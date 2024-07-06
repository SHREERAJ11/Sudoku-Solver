#include <iostream>
#include <vector>

#define UNASSIGNED 0
#define N 9

bool isSafe(std::vector<std::vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool findUnassignedLocation(std::vector<std::vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(std::vector<std::vector<int>>& grid) {
    int row, col;
    
    if (!findUnassignedLocation(grid, row, col)) {
        return true;
    }
    
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (solveSudoku(grid)) {
                return true;
            }
            
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    /*
    std::vector<std::vector<int>> grid(N, std::vector<int>(N));

    std::cout << "Enter the Sudoku puzzle (0 for empty cells):" << std::endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            std::cin >> grid[row][col];
        }
    }

    std::cout << "Input Sudoku grid:" << std::endl;
    printGrid(grid);
    */
    
    
    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        std::cout << "No solution exists" << std::endl;
    }
    
    return 0;
}
