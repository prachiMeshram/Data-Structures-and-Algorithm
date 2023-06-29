// https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// TABULATION
int lcs(string &str1, string &str2){
	//	Write your code here.
	int ans = 0;

	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = 0;
			}
			ans = max (ans, dp[i][j]);
		}
	}

	return ans;
}