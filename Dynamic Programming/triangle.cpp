// https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// SIMPLE RECURSION
int solve (vector<vector<int>>& triangle, int n, int i, int j) {
	if (i == n-1) {
		return triangle[i][j];
	}

	int down = triangle[i][j] + solve(triangle, n, i+1, j);
	int diag = triangle[i][j] + solve(triangle, n, i+1, j+1);

	return min(down,diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return solve(triangle, n, 0, 0);
}

// SIMPLE RECURSION WITH DP
int solve (vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>>& dp) {
	if (i == n-1) {
		return dp[i][j] = triangle[i][j];
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int down = triangle[i][j] + solve(triangle, n, i+1, j, dp);
	int diag = triangle[i][j] + solve(triangle, n, i+1, j+1, dp);

	return dp[i][j] = min(down,diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (n, -1));

	solve(triangle, n, 0, 0, dp);
	
	return dp[0][0];
}

// TABULATION
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (n, -1));

	for (int i = n-1; i >= 0; i--) {

		for (int j = 0; j < n; j++) {
			if (i == n-1) {
				dp[i][j] = triangle[i][j];
			}
			else {
				int dw = triangle[i][j] + dp[i+1][j];  
				int dg = triangle[i][j] + dp[i+1][j+1];  
				dp[i][j] = min(dw, dg);
			}
		}
	}
	
	return dp[0][0];
}


// SPACE OPTIMIZATION
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int> prev(n, -1);

	for (int i = n-1; i >= 0; i--) {
		vector<int> curr(n, -1);
		for (int j = 0; j < n; j++) {
			if (i == n-1) {
				curr[j] = triangle[i][j];
			}
			else {
				int dw = triangle[i][j] + prev[j];  
				int dg = triangle[i][j] + prev[j+1];  
				curr[j]= min(dw, dg);
			}
		}
		prev = curr;
	}
	
	return prev[0];
}