// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int f(int ind, int buy, vector<int>& prices, int n) {
        if (ind >= n) {
            return 0;
        }

        if (buy) {
            return max( -prices[ind] + f(ind+1, 0, prices, n), 0 + f(ind+1, 1, prices, n));
        }
        return max( prices[ind] + f(ind+2, 1, prices, n), 0 + f(ind+1, 0, prices, n));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0, 1, prices, n);
    }
};