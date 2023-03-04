#include <iostream>
#include "sudoku_solver.h"

using namespace std;

void printPuzzle(int **puzzle)
{
    for (int i = 0; i < 9; i++)
        cout << " -----";
    cout << endl;
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << "|"
                 << "  " << puzzle[row][col] << "  ";
        cout << "|" << endl;
        for (int i = 0; i < 9; i++)
            cout << " -----";
        cout << endl;
    }
}

int main()
{
    system("cls");
    int **puzzle = new int *[9];
    for (int i = 0; i < 9; i++)
        puzzle[i] = new int[9];
    cout << "\nEnter the numbers in a Standard 9x9 Sudoku (Use 0 to represent unassigned cells):\n\n";
    for (int i = 0; i < 9; i++)
    {
        cout << "Row " << i + 1 << ":\n\n";
        for (int j = 0; j < 9; j++)
            cin >> puzzle[i][j];
        cout << '\n';
    }
    system("cls");
    cout << "Entered Puzzle:\n\n";
    printPuzzle(puzzle);
    cout << "\nSolution:\n\n";
    if (sudoku.solver(puzzle))
        printPuzzle(puzzle);
    else
        cout << "No solution exists.\n";
    cout << endl;
    system("pause");
    return 0;
}