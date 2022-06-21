# Sudoku-Solver
This is a C++ program to solve a standard 9x9 sudoku entered by the user. Sudoku is a logic-based puzzle game that requires you to combine numbers to come completely fill the board. The objective is for you to fill a 9x9 grid so that each column, each row, and each of the nine 3x3 sub grids that compose the grid contain all the digits from 1–9.

# Design Technique Used: 
Backtracking

# Approach:

Before assigning a number, checked whether it is safe to assign. Checked that the same number is not present in the current row, current column and current 3X3 sub grid. After checking for safety, assigned the number, and recursively checked whether this assignment leads to a solution or not. If the assignment didn’t lead to a solution, then tried the next number for the current empty cell. And if none of the number (1 to 9) led to a solution, returned false and printed no solution exists.

# Output: 

![image](https://user-images.githubusercontent.com/91213354/174858109-419aa357-39b6-4076-af9c-35a46d760002.png)
