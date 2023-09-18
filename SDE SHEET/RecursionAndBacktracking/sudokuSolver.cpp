// https://www.codingninjas.com/studio/problems/sudoku-solver_8416969?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

bool isSafe (int board[][9], int row, int col, int digit) {
    
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == digit || board[i][col] == digit) {
            return false;
        }
    }

    int sr = (row/3) * 3;
    int sc = (col/3) * 3;

    for (int i = sr; i < sr+3 ; i++) {
        for (int j = sc; j < sc+3; j++) {
            if (board[i][j] == digit) {
                return false;
            }
        }
    }
    return true;
}
bool solve (int board[][9], int row, int col) {
    // base case 
    if (row == 9) {
        return true;
    }
    
    int newR = row, newC = col+1;
    if (col+1 == 9) {
        newR = row+1;
        newC = 0;
    }

    if (board[row][col] != 0) {
        return solve(board, newR, newC);
    }
    
    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] = digit;
            if (solve(board, newR, newC)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    
    return false;
}
bool sudokuSolver(int board[][9]) {
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Don't print output and return output as specified in the question
    */
    return solve (board, 0, 0);
}