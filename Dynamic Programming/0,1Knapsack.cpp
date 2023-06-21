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