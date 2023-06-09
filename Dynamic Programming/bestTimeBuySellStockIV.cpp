// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<bits/stdc++.h>
using namespace std;

// recursion
class Solution {
private:
    int f(int ind, int transNo, vector<int>& prices, int n, int k) {
        if (ind == n || transNo == 2*k+1) {
            return 0;
        }

        if (transNo % 2 == 0) { // buy
            return max ( -prices[ind] + f(ind+1, transNo + 1, prices, n, k), 0 + f(ind+1, transNo, prices, n, k) );
        }
        return max ( prices[ind] + f(ind+1, transNo + 1, prices, n, k), 0 + f(ind+1, transNo, prices, n, k) ) ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =  prices.size();

        return f(0, 0, prices, n, k);
    }
};

// using DP

class Solution {
private:
    int f(int ind, int transNo, vector<int>& prices, int n, int k, vector<vector<int>> &dp) {
        if (ind == n || transNo == 2*k+1) {
            return 0;
        }

        if (dp[ind][transNo] != -1) {
            return dp[ind][transNo];
        }

        if (transNo % 2 == 0) { // buy
            return dp[ind][transNo] = max ( -prices[ind] + f(ind+1, transNo + 1, prices, n, k, dp), 0 + f(ind+1, transNo, prices, n, k, dp) );
        }
        return dp[ind][transNo] = max ( prices[ind] + f(ind+1, transNo + 1, prices, n, k, dp), 0 + f(ind+1, transNo, prices, n, k, dp) ) ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =  prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2*k+1, -1));

        return f(0, 0, prices, n, k, dp);
    }
};

// TABULATION 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =  prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int transNo = 2*k-1; transNo >= 0; transNo--) {
                if (transNo % 2 == 0) { // buy
                    dp[ind][transNo] = max ( -prices[ind] + dp[ind+1][transNo+1], 0 + dp[ind+1][transNo] );
                }
                else {
                    dp[ind][transNo] = max ( prices[ind] + dp[ind+1][transNo+1], 0 + dp[ind+1][transNo] ) ;
                }
            }
        }

        return dp[0][0];
    }
};

// SPACE OPT

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =  prices.size();

        vector<int> ahead(2*k+1, 0);
        vector<int> cur(2*k+1, 0);

        for (int ind = n-1; ind >= 0; ind--) {
            for (int transNo = 2*k-1; transNo >= 0; transNo--) {
                if (transNo % 2 == 0) { // buy
                    cur[transNo] = max ( -prices[ind] + ahead[transNo+1], 0 + ahead[transNo] );
                }
                else {
                    cur[transNo] = max ( prices[ind] + ahead[transNo+1], 0 + ahead[transNo] ) ;
                }
            }
            ahead = cur;
        }

        return ahead[0];
    }
};