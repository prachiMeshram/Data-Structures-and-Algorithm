// https://leetcode.com/problems/burst-balloons/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int f(int i, int j, vector<int> &a) {
        if (i > j) {
            return 0;
        }

        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++) {
            int coins = a[i-1]*a[ind]*a[j+1] + f(i, ind-1, a) + f(ind+1, j, a);
            maxi = max(maxi, coins);
        }
        return maxi;
    }
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        vector<int> a = nums;

        a.push_back(1);
        a.insert(a.begin(), 1);

        return f(1, n, a);
    }
};