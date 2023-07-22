// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int> &arr) {
    if (i==j) {
        return 0;
    }

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int steps = f(i, k, arr) + f(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini, steps);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return f(1, N-1, arr);
}

// MEMOISATION
#include <bits/stdc++.h> 

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if (i==j) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int steps = f(i, k, arr, dp) + f(k+1, j, arr, dp) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int> (N, -1));

    return f(1, N-1, arr, dp);
}

// TABULATION

#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int> (N, -1));

    for (int i = 1; i < N; i++) {
        dp[i][i] = 0; 
    }

    for (int i = N-1; i > 0; i--) {
        for (int j = i+1; j < N; j++) {
            int mini = INT_MAX;

            for (int k = i; k < j; k++) {
                int steps = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}