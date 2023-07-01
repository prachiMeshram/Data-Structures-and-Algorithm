// https://www.codingninjas.com/studio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int lcs(int i, int j, string s1, string s2,  vector<vector<int>> &dp) {
    if (i < 0 || j < 0 ) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, dp);
    }
    else {
        return dp[i][j] = 0 + max (lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
    }
}
int minInsertion(string &str)
{
    // Write your code here.
    int n = str.size();
    string s1 = str;
    string s2 = str;

    int st = 0;
    int ed = n-1;

    while (st<=ed) {
        swap(s2[st++], s2[ed--]);
    }

    vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j-1];
            }
            else {
                curr[j] = 0 + max (prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return str.size() - prev[n];
}