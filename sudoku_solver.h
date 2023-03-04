#include <iostream>

using namespace std;

class BacktrackingSudokuSolver
{

private:
    bool findEmptyCell(int **grid, int &row, int &col)
    {
        for (row = 0; row < 9; row++)
        {
            for (col = 0; col < 9; col++)
            {
                if (grid[row][col] == 0)
                    return true;
            }
        }
        return false;
    }

    bool isSafe(int **grid, int row, int col, int num)
    {
        return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3, col - col % 3, num);
    }

    bool usedInRow(int **grid, int row, int num)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == num)
                return true;
        }
        return false;
    }

    bool usedInCol(int **grid, int col, int num)
    {
        for (int row = 0; row < 9; row++)
        {
            if (grid[row][col] == num)
                return true;
        }
        return false;
    }

    bool usedInBox(int **grid, int boxStartRow, int boxStartCol, int num)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (grid[row + boxStartRow][col + boxStartCol] == num)
                    return true;
            }
        }
        return false;
    }

public:
    bool solver(int **grid)
    {
        int row, col;

        if (!findEmptyCell(grid, row, col))
            return true; // solved

        for (int num = 1; num <= 9; num++)
        {
            if (isSafe(grid, row, col, num))
            {
                grid[row][col] = num;

                if (solver(grid))
                    return true;

                grid[row][col] = 0; // backtrack
            }
        }
        return false; // unsolvable
    }
} sudoku;
