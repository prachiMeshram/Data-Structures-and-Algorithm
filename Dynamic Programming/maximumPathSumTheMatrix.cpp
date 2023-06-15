//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// RECURSION
int f(int i, int j, vector<vector<int>> &matrix) {
    
    if (i == 0) {
        return matrix[0][j];
    }
    if (j < 0 || j >= matrix[0].size()) {
        return -1e9;
    }

    int up = matrix[i][j] + f(i-1, j, matrix);
    int ld = matrix[i][j] + f(i-1, j-1, matrix);
    int rd = matrix[i][j] + f(i-1, j+1, matrix);

    return max(up, max(ld, rd));
}

// Using DP
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    
    if (j < 0 || j >= matrix[0].size()) {
        return -1e9;
    }

    if (i == 0) {
        return matrix[0][j];
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = matrix[i][j] + f(i-1, j, matrix, dp);
    int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
    int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);

    return dp[i][j] = max(up, max(ld, rd));
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    int maxi = -1e9;

    for (int i = 0; i < m; i++) {
        maxi = max(maxi, f(n-1, i, matrix));
    }

    return maxi;
}


#include <bits/stdc++.h>

// tabulation
int getMaxPathSum(vector<vector<int>> &matrix) {
  //  Write your code here.
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));

  for (int j = 0; j < m; j++) {
    dp[0][j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ld = INT_MIN;
      int rd = INT_MIN;

      int up = matrix[i][j] + dp[i - 1][j];
      if (j - 1 >= 0) {
        ld = matrix[i][j] + dp[i - 1][j - 1];
      } 
      if (j + 1 < m) {
        rd = matrix[i][j] + dp[i - 1][j + 1];
      } 

      dp[i][j] = max(up, max(ld, rd));
    }
  }

  int maxi = INT_MIN;

  for (int j = 0; j < m; j++) {
    maxi = max(maxi, dp[n - 1][j]);
  }

  return maxi;
}

// SPACE OPTIMIZATION 
int getMaxPathSum(vector<vector<int>> &matrix) {
  //  Write your code here.
  int n = matrix.size();
  int m = matrix[0].size();
  vector<int> prev(m, 0);

  for (int j = 0; j < m; j++) {
    prev[j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {
    vector<int> curr(m, 0);
    for (int j = 0; j < m; j++) {
      int ld = INT_MIN;
      int rd = INT_MIN;

      int up = matrix[i][j] + prev[j];
      if (j - 1 >= 0) {
        ld = matrix[i][j] + prev[j - 1];
      } 
      if (j + 1 < m) {
        rd = matrix[i][j] + prev[j + 1];
      } 

      curr[j] = max(up, max(ld, rd));
    }

    prev = curr;
  }

  int maxi = INT_MIN;

  for (int j = 0; j < m; j++) {
    maxi = max(maxi, prev[j]);
  }

  return maxi;
}