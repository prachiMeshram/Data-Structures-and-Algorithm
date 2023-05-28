#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> board) {
    cout << "--- chess borad ---";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    // vertically top
    for (int i = row-1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // diagonally left
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // diagonally right
    for (int i = row-1, j = col+1; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}


void nQueens(vector<vector<char>> board, int row) {
    // base case 
    if (row == board.size()) {
        printBoard(board);
        return;
    }

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            nQueens(board, row+1); // recursion call
            board[row][col] = 'X'; // backtracking 
        }
    }
} 

int main () {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, 'X'));

    nQueens(board, 0); 

    return 0;
}