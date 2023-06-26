// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// recursion
int fun(int ind, int N, vector<int> &price) {
	if (ind == 0) {
		return price[0]*N;
	}

	int notTake = 0 + fun (ind-1, N, price);

	int take = INT_MIN;
	int rodLen = ind+1;
	if (rodLen <= N) {
		take = price[ind] + fun(ind, N - rodLen, price);
	}

	return  max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	
	return fun(price.size() -1, n, price);
}



// USING DP
int fun(int ind, int N, vector<int> &price, vector<vector<int>> &dp) {
	if (ind == 0) {
		return price[0]*N;
	}

	if (dp[ind][N] != -1) {
		return dp[ind][N];
	}

	int notTake = 0 + fun (ind-1, N, price, dp);

	int take = INT_MIN;
	int rodLen = ind+1;
	if (rodLen <= N) {
		take = price[ind] + fun(ind, N - rodLen, price, dp);
	}

	dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(price.size(), vector<int>(n+1, -1));
	
	return fun(price.size() -1, n, price, dp);
}



// TABULATION

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n+1, 0));

	for (int i = 0; i <= n; i++) {
		dp[0][i] = price[0]*i;
	}
	
	for (int ind = 1; ind < n; ind++) {
		for (int len = 0; len <= n; len++) {

			int notTake = 0 + dp[ind-1][len];

			int take = INT_MIN;
			int rodLen = ind+1;
			if (rodLen <= len) {
				take = price[ind] + dp[ind][len-rodLen];
			}

			dp[ind][len] = max(take, notTake);
		}
	}

	return dp[n-1][n];
}


// SPACE OPTIMISATION WITH 1D ARRAY

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n+1, 0);

	for (int i = 0; i <= n; i++) {
		prev[i] = price[0]*i;
	}
	
	for (int ind = 1; ind < n; ind++) {
		for (int len = 0; len <= n; len++) {

			int notTake = 0 + prev[len];

			int take = INT_MIN;
			int rodLen = ind+1;
			if (rodLen <= len) {
				take = price[ind] + prev[len-rodLen];
			}

			prev[len] = max(take, notTake);
		}
	}

	return prev[n];
}

