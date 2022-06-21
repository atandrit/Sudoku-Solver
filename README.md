# Sudoku-Solver
This is a C++ program to solve a standard 9x9 sudoku entered by the user. Sudoku is a logic-based puzzle game that requires you to combine numbers to come completely fill the board. The objective is for you to fill a 9x9 grid so that each column, each row, and each of the nine 3x3 sub grids that compose the grid contain all the digits from 1–9.

# Design Techniques Used: 
Backtracking

# Approach:

Before assigning a number, checked whether it is safe to assign. Checked that the same number is not present in the current row, current column and current 3X3 sub grid. After checking for safety, assigned the number, and recursively checked whether this assignment leads to a solution or not. If the assignment didn’t lead to a solution, then tried the next number for the current empty cell. And if none of the number (1 to 9) led to a solution, returned false and printed no solution exists.

# Source Code:

#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED;
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << '\t';
        cout << endl;
    }
}

int main()
{
    system("cls");
    int grid[N][N];
    cout << "\nEnter the numbers in a Standard 9x9 Sudoku (Use 0 to represent unassigned cells):\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << "Row " << i + 1 << ":\n\n";
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
        cout << '\n';
    }
    system("cls");
    cout << "Sudoku Entered:\n\n";
    printGrid(grid);
    cout << "\nSolution:\n\n";
    if (SolveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists.\n";
    cout << endl;
    system("pause");
    return 0;
}

# Output: 

![image](https://user-images.githubusercontent.com/91213354/174858109-419aa357-39b6-4076-af9c-35a46d760002.png)
