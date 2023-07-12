// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

// RECURSION
class Solution
{
private:
    int f(int ind, int buy, vector<int> &prices, int fee, int n)
    {
        if (ind == n)
        {
            return 0;
        }

        if (buy)
        {
            return max(-prices[ind] + f(ind + 1, 0, prices, fee, n), 0 + f(ind + 1, 1, prices, fee, n));
        }
        else
        {
            return max(prices[ind] - fee + f(ind + 1, 1, prices, fee, n), 0 + f(ind + 1, 0, prices, fee, n));
        }
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        return f(0, 1, prices, fee, n);
    }
};

// MEMOISATION
class Solution
{
private:
    int f(int ind, int buy, vector<int> &prices, int fee, int n, vector<vector<int>> dp)
    {
        if (ind == n)
        {
            return 0;
        }

        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }

        if (buy)
        {
            return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, fee, n, dp), 0 + f(ind + 1, 1, prices, fee, n, dp));
        }
        else
        {
            return dp[ind][buy] = max(prices[ind] - fee + f(ind + 1, 1, prices, fee, n, dp), 0 + f(ind + 1, 0, prices, fee, n, dp));
        }
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, fee, n, dp);
    }
};

// TABULATION
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);

            dp[ind][0] = max(prices[ind] - fee + dp[ind + 1][1], 0 + dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};