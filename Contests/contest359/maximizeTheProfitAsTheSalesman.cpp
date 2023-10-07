// https://leetcode.com/contest/weekly-contest-359/problems/maximize-the-profit-as-the-salesman/

// Maximize the Profit as the Salesman

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findNext(int i, vector<vector<int>>& offers, int x) {
        int s = i;
        int e = offers.size() - 1;
        
        int ans = -1;
        while (s <= e) {
            int mid = s + (e-s)/2;
            if (offers[mid][0] > x) {
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        return ans;
    }
    
    int solve (int ind, vector<vector<int>>& offers, vector<int> &dp) {
        
        if (ind >= offers.size()) {
            return 0;
        }
        if (dp[ind] != -1) return dp[ind];
        
        int next = findNext(ind+1, offers, offers[ind][1]);
        int take = 0;
        take = offers[ind][2] + solve(next, offers, dp);
        int notTake = solve (ind+1, offers, dp);
        
        return dp[ind] = max(take, notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(offers.size(), -1);
        
        sort(offers.begin(), offers.end());
        
        return solve (0, offers, dp);
        
    }
};