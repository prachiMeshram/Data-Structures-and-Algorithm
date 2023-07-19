// https://leetcode.com/problems/longest-string-chain/

#include<bits/stdc++.h>
using namespace std;

bool comp(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

class Solution {
    
public:
    bool isPossible(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) {
            return false;
        }
        int i = 0;
        int j = 0;

        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if (i == s1.size() && j == s2.size()) {
            return true;
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), comp);
        // sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (isPossible(words[i], words[prev]) && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};