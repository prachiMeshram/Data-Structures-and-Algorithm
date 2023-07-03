// https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int n = a.size();
	int m = b.size();
	string ans = "";

	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = 0 + max (dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int i = n, j = m;

	while (i > 0 && j > 0) {
		if (a[i-1] == b[j-1]) {
			ans += a[i-1];
			i--;
			j--;
		}
		else if (dp[i-1][j] > dp[i][j-1]) {
			ans += a[i-1];
			i--;
		}
		else {
			ans += b[j-1];
			j--;
		}
	}

	while (i > 0) {
		ans += a[i-1];
		i--;
	}
	while (j > 0) {
		ans += b[j-1];
		j--;
	}

	reverse (ans.begin(), ans.end());

	return ans;
}