// https://www.codingninjas.com/studio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;


// RECURSION
long f(int ind, int buy, long *values, int n) {
    if (ind == n) {
        return 0;
    }

    long profit = 0;
    if (buy) {
        profit = max( -values[ind] + f(ind+1, 0, values, n), 0 + f(ind+1, 1, values, n));
    }
    else {
        profit = max ( values[ind] + f(ind+1, 1, values, n), 0 + f(ind+1, 0, values, n));
    }

    return profit;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    return f(0, 1, values, n);
}

// USING DP

long f(int ind, int buy, long *values, int n, vector<vector<int>> &dp) {
    if (ind == n) {
        return 0;
    }

    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;
    if (buy) {
        profit = max( -values[ind] + f(ind+1, 0, values, n, dp), 0 + f(ind+1, 1, values, n, dp));
    }
    else {
        profit = max( values[ind] + f(ind+1, 1, values, n, dp), 0 + f(ind+1, 0, values, n, dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<int>> dp (n, vector<int> (2, -1)); 
    return f(0, 1, values, n, dp);
}

// TABULATION 
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>> dp (n+1, vector<long> (2, 0)); 
    dp[n][0] = dp[n][1] = 0;

    for (int ind = n-1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if (buy) {
                profit = max( -values[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else {
                profit = max( values[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][1];
}

// SPACE OPT

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<long> ahead(2, 0), curr(2, 0); 
    ahead[0] = ahead[1] = 0;

    for (int ind = n-1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if (buy) {
                profit = max( -values[ind] + ahead[0], 0 + ahead[1]);
            }
            else {
                profit = max( values[ind] + ahead[1], 0 + ahead[0]);
            }

            curr[buy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];
}