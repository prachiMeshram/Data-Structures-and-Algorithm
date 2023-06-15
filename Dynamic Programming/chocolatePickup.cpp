// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

// normal recursion
int f(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c) {
  // out of bound cases
  if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
    return -1e8;
  }
  // base case
  if (i == r - 1) {
    if (j1 == j2) {
      return grid[i][j1];
    } else {
      return grid[i][j1] + grid[i][j2];
    }
  }
  int maxi = -1e8;
  for (int dj1 = -1; dj1 <= 1; dj1++) {
    for (int dj2 = -1; dj2 <= 1; dj2++) {
      int ans = 0;
      if (j1 == j2) {
        ans = grid[i][j1];
      } else {
        ans = grid[i][j1] + grid[i][j2];
      }
      ans += f(i + 1, j1 + dj1, j2 + dj2, grid, r, c);
      maxi = max(maxi, ans);
    }
  }

  return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  // Write your code here.

  return f(0, 0, c - 1, grid, r, c);
}


// recursion + DP 
int f(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c,
      vector<vector<vector<int>>> &dp) {
  // out of bound cases
  
  if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
    return -1e9;
  }
  
  // base case
  if (i == r - 1) {
    if (j1 == j2) {
      return grid[i][j1];
    } else {
      return grid[i][j1] + grid[i][j2];
    }
  }

  if (dp[i][j1][j2] != -1) {
    return dp[i][j1][j2];
  }

  int maxi = INT_MIN;
  for (int dj1 = -1; dj1 <= 1; dj1++) {
    for (int dj2 = -1; dj2 <= 1; dj2++) {
      int ans = 0;
      if (j1 == j2) {
        ans = grid[i][j1];
      } else {
        ans = grid[i][j1] + grid[i][j2];
      }
      ans += f(i + 1, j1 + dj1, j2 + dj2, grid, r, c, dp);
      maxi = max(maxi, ans);
    }
  }

  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  // Write your code here.
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

  return f(0, 0, c - 1, grid, r, c, dp);
}
