// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<bits/stdc++.h>
using namespace std;

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