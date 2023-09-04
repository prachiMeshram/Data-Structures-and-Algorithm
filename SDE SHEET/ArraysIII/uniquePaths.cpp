// https://www.codingninjas.com/studio/problems/1081470?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int countPaths(int m, int n, int i, int j, vector<vector<int>> &dp) {
	if (i == m-1 && j == n-1) {
		return 1;
	}
	if (i >= m || j >= n) {
		return 0;
	}
	
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	return dp[i][j] = countPaths( m, n, i+1, j, dp) + countPaths( m, n, i, j+1, dp);
}
int uniquePaths(int m, int n) {
	// Write your code here.

	vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

	int num = countPaths(m, n, 0, 0, dp);
	if (m == 1 && n == 1) {
		return num;
	}
	return dp[0][0];
}