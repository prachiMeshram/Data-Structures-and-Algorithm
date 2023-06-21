// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// recursion plus dp
int fun (int ind, vector<int> &weight, vector<int> &value,int maxWeight, vector<vector<int>> &dp) {
	// base case 
	if (ind == 0) {
		if (weight[0] <= maxWeight) {
			return value[0];
		}
		return 0;
	}

	if (dp[ind][maxWeight] != -1) {
		return dp[ind][maxWeight];
	}

	int notTake = fun (ind-1, weight, value, maxWeight, dp);
	int take = INT_MIN;
	if (weight[ind] <= maxWeight) {
		take = value[ind] + fun (ind-1, weight, value, maxWeight-weight[ind], dp);
	}

	dp[ind][maxWeight] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	return fun(n-1, weight, value, maxWeight, dp);
}


// TABULATION
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

	for (int w = weight[0]; w <= maxWeight; w++) {
		dp[0][w] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int w = 0; w <= maxWeight; w++) {

			int notTake = 0 + dp[ind-1][w];

			int take = INT_MIN;
			if (weight[ind] <= w) {
				take = value[ind] + dp[ind-1][w-weight[ind]];
			}

			dp[ind][w] = max(take, notTake);
		}
	}

	return dp[n-1][maxWeight];
}

// space optimisation with two vectors

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1, 0);
	vector<int> curr(maxWeight+1, 0);

	for (int w = weight[0]; w <= maxWeight; w++) {
		prev[w] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int w = 0; w <= maxWeight; w++) {

			int notTake = 0 + prev[w];

			int take = INT_MIN;
			if (weight[ind] <= w) {
				take = value[ind] + prev[w-weight[ind]];
			}

			curr[w] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxWeight];
}