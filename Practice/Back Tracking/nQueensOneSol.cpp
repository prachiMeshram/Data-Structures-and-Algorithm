#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> &board) {
    cout << "--- chess board ---"<< endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col) {
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


bool nQueens(vector<vector<char>> &board, int row) {
    // base case 
    if (row == board.size()) {
        return true;
    }

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            if (nQueens(board, row+1) ) {
                return true;
            }
            board[row][col] = 'X'; // backtracking 
        }
    }
    return false;
} 


int main () {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, 'X'));

    if (nQueens(board, 0)) {
        cout << "solution is possible" << endl; 
        printBoard(board);
    }
    else {
        cout << "solution is not possible" << " ";
    }

    return 0;
}    