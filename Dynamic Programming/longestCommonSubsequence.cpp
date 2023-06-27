// https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;

int fun ( int i, int j, string &s, string &t, vector<vector<int>> &dp) {

	// base case 
	if ( i < 0 || j < 0) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return  dp[i][j] =  1 + fun( i-1, j-1, s, t, dp);
	}

	return  dp[i][j] =  0 + max(fun( i-1, j, s, t, dp), fun( i, j-1, s, t, dp));
}

int lcs(string s, string t)
{
	//Write your code here
	int n = s.size();
	int m = t.size();

	vector<vector<int>> dp (n, vector<int> (m, -1));

	return fun(n-1, m-1, s, t, dp);
}