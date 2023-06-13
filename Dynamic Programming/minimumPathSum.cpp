// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


#include <bits/stdc++.h> 
using namespace std;

// NORMAL RECURSION (TLE)
int solve(int i, int j, vector<vector<int>> &grid) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    if (i < 0 || j < 0) {
        return 1e9;
    } 

    int up = grid[i][j] + solve(i-1, j, grid);
    int left = grid[i][j] + solve(i, j-1, grid);

    return min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<int>> dp;

    return solve(n-1, m-1, grid);
}

// recusion with DP
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    if (i < 0 || j < 0) {
        return 1e9;
    } 
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = grid[i][j] + solve(i-1, j, grid, dp);
    int left = grid[i][j] + solve(i, j-1, grid, dp);

    return dp[i][j] =  min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));

    return solve(n-1, m-1, grid, dp);
}

// TABULATION
int minSumPath(vector<vector<int>> &grid) {
  // Write your code here.

  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = grid[i][j];
      } 
      else {
          int up = 0; 
          int left = 0; 
          if (i > 0) {
            up = grid[i][j] + dp[i - 1][j];
          }
          else {
              up = INT_MAX;
          }
          if (j > 0) {
            left = grid[i][j] + dp[i][j - 1];
          }
          else {
              left = INT_MAX;
          }
          dp[i][j] = min(up, left);
      }
    }
  }

  return dp[n-1][m-1];
}