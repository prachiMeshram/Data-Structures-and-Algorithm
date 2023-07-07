// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int profit = 0;
        int mini = prices[0];

        for (int i = 1; i < n; i++) {

            profit = max(prices[i] - mini, profit);
            mini = min (mini, prices[i]);
        }

        return profit;
    }
};