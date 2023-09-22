// https://www.codingninjas.com/studio/problems/759332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// APPROCH 1
void addSol(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe (int row, int col, vector<vector<int>> &board, int n) {
    
    int x = row;
    int y = col;

    while(y>=0){
       if(board[x][y] ==1){
           return false;
       }
       y--;
    }
    x = row;
    y = col;

    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    
    while(x<n && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void solve (int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    if (col == n) {
        addSol(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board (n, vector<int> (n, 0));
    vector<vector<int>> ans;
    solve (0, ans, board, n);
    return ans;
}

//OPTIMISED SPACE COMPLEXITY
void addSol(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}


void solve (int col, vector<vector<int>> &ans, vector<vector<int>> &board, vector<int> &leftR, vector<int> &upperD, vector<int> &lowerD, int n) {
    if (col == n) {
        addSol(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftR[row]==0 && lowerD[row+col]==0 && upperD[n-1+col-row]==0) {
            board[row][col] = 1;
            leftR[row] = 1;
            upperD[n-1+col-row] = 1;
            lowerD[row+col] = 1;
            solve(col+1, ans, board, leftR, upperD, lowerD, n);
            board[row][col] = 0;
            leftR[row] = 0;
            upperD[n-1+col-row] = 0;
            lowerD[row+col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board (n, vector<int> (n, 0));
    vector<vector<int>> ans;
    vector<int> leftR(n, 0), upperD(2*n-1, 0), lowerD(2*n-1, 0);
    solve (0, ans, board, leftR, upperD, lowerD, n);
    return ans;
}