// https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case 
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            return dp[i][j] =  1 + lcs(i-1, j-1, s1, s2, dp);
        }
        else {
            return dp[i][j] =  0 + max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;

        int st = 0;
        int ed = s1.size()-1;
        while (st <= ed) {
            swap(s2[st++], s2[ed--]);
        }

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return lcs(n-1, m-1, s1, s2, dp);
    }
};