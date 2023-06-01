// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int recurSolve(int i, int j) {
	// base case 
	// TLE
	if (i == 0 && j == 0) {
		return 1;
	}
	if (i<0 || j<0) {
		return 0;
	}

	int left = recurSolve(i, j-1);
	int top = recurSolve(i-1, j);

	return left + top; 
}

int memoiSolve(int i, int j, vector<vector<int>> &dp) {
	// base case 
	if (i == 0 && j == 0) {
		return 1;
	}
	if (i<0 || j<0) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int left = memoiSolve(i, j-1, dp);
	int top = memoiSolve(i-1, j, dp);

	return dp[i][j] = left + top; 
}




int uniquePaths(int m, int n) {
	// Write your code here.

	vector<vector<int>> dp(m, vector<int>(n, -1));

	// TABULATION
	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		if (i == 0) {
	// 			dp[i][j] = 1;
	// 		}
	// 		else {
				int left = 0;
				int top = 0;
	// 			if (j>0) left = dp[i][j-1];
	// 			if (i>0) top = dp[i-1][j];
	// 			dp[i][j] = left + top;
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];



	// SPACE OPTIMIZATION
	// vector<int> prev(n, 1);

	// for (int i = 1; i < m; i++) {
	// 	vector<int> curr(n, -1);

	// 	for (int j = 0; j < n; j++) {
	// 		curr[j] = curr[j-1] + prev[j];
	// 	}

	// 	prev = curr;
	// }
	// return prev[n-1];
	
	// return recurSolve(m-1, n-1);
	return memoiSolve(m-1, n-1, dp);
}