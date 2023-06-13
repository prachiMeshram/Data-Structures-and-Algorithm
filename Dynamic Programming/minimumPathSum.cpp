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