#include <bits/stdc++.h>
using namespace std;

void printSudoku(vector<vector<int>> &vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect.size(); j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe (vector<vector<int>> &vect, int row, int col, int digit) {

    // check vertically
    for (int i = 0; i < 9; i++) {
        if (vect[i][col] == digit) {
            return false;
        }
    }

    // check horizontally
    for (int j = 0; j < 9; j++) {
        if (vect[row][j] == digit) {
            return false;
        }
    }

    // check within grid (3x3)
    int sr = (row/3) * 3;
    int sc = (col/3) * 3;

    for (int i = sr; i < sr+3; i++) {
        for (int j = sc; j < sc+3; j++) {
            if (vect[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSover(vector<vector<int>> &vect, int row, int col) {
    // base case 
    if (row == 9) {
        return true;
    }

    // recursion 
    int newRow = row;
    int newCol = col+1;
    if (newCol == 9) {
        newRow++;
        newCol = 0;
    }

    if (vect[row][col] != 0) {
        return sudokuSover(vect, newRow, newCol);
    }

    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe (vect, row, col, digit)) {
            vect[row][col] = digit;
            if (sudokuSover(vect, newRow, newCol)) {
                return true;
            }
            vect[row][col] = 0;
        }
    }

    return false;
}


int main() {

    vector<vector<int>> vect(9, vector<int>(9, 0));

    vect = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };

    if (sudokuSover(vect, 0, 0)) {
        cout << "Solution exists:" << endl;
        printSudoku(vect);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
