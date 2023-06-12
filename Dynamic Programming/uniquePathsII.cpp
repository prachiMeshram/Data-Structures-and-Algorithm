// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<iostream>
#include<vector>
using namespace std;


// NORMAL RECURSIVELY
int solve(int i, int j, vector< vector< int> > &mat) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i>=0 && j>= 0 && mat[i][j] == -1) {
        return 0;
    }
    if (i < 0 || j < 0) {
        return 0;
    }

    int up = solve(i-1, j, mat);
    int left = solve(i, j-1, mat);
    
    return up + left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return solve(n-1, m-1, mat);
}

// RECURSIVELY with DP
int mod = (int) (1e9 + 7);
int solve(int i, int j, vector< vector< int> > &mat, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) {
        dp[0][0] = 1;
        return 1;
    }
    if (i>=0 && j>= 0 && mat[i][j] == -1) {
        dp[i][j] = 0;
        return 0;
    }
    if (i < 0 || j < 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = solve(i-1, j, mat, dp);
    int left = solve(i, j-1, mat, dp);
    dp[i][j] = (up + left)%mod;

    return dp[i][j];
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp (n, vector<int> (m, -1));
    solve(n-1, m-1, mat, dp);
    return dp[n-1][m-1];
}