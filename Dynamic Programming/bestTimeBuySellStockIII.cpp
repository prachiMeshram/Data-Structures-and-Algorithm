// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int f(int ind, int buy, int cap, vector<int>& prices, int n) {
    if (cap == 0 || ind == n) {
        return 0;
    }

    if (buy) {
        return max( -prices[ind] + f(ind+1, 0, cap, prices, n), 0 + f(ind+1, 1, cap, prices, n));
    }

    return max (prices[ind] + f(ind+1, 1, cap-1, prices, n), 0 + f(ind+1, 0, cap, prices, n));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0, 1, 2, prices, n);
    }
};

// USING DP

class Solution {
private: 
    int f(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>> &dp) {
    if (cap == 0 || ind == n) {
        return 0;
    }

    if (dp[ind][buy][cap] != -1) {
        return dp[ind][buy][cap];
    }

    if (buy) {
        return dp[ind][buy][cap] = max( -prices[ind] + f(ind+1, 0, cap, prices, n, dp), 0 + f(ind+1, 1, cap, prices, n, dp));
    }

    return dp[ind][buy][cap] = max(prices[ind] + f(ind+1, 1, cap-1, prices, n, dp), 0 + f(ind+1, 0, cap, prices, n, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));

        return f(0, 1, 2, prices, n, dp);
    }
};

// TABULATION 

class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        dp[ind][buy][cap] = max( -prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    }
                    else {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }      
                }
            }
        }

        return dp[0][1][2];
    }
};

// SPACE OPT
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int> (3, 0));
        vector<vector<int>> cur(2, vector<int> (3, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        cur[buy][cap] = max( -prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                    }
                    else {
                        cur[buy][cap] = max(prices[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);
                    }      
                }
            }
            ahead = cur;
        }

        return ahead[1][2];
    }
};