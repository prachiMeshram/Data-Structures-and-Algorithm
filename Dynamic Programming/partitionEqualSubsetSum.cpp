// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	if (sum&1) {
		return false;
	}

	int k = sum/2;
	vector<vector<int>> dp(n, vector<int> (k+1, 0));
	for (int i = 0; i < n; i++) {
		dp[i][0] == true;
	}
	if (arr[0] <= k) {
		dp[0][arr[0]] = true;
	}

	for (int ind = 1; ind < n; ind++) {
		for (int target = 1; target <= k; target++) {
			bool notTake = dp[ind-1][target];
			bool take;
			if (arr[ind] <= target) {
				take = dp[ind-1][target-arr[ind]];
			}
			dp[ind][target] = take || notTake;
		}
	}	

	return dp[n-1][k];
}
