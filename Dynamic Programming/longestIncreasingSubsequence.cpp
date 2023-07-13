// https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(int ind, int prev, vector<int> &nums, int n)
    {
        if (ind == n)
        {
            return 0;
        }

        int notTake = 0 + f(ind + 1, prev, nums, n);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev])
        {
            take = 1 + f(ind + 1, ind, nums, n);
        }

        return max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return f(0, -1, nums, n);
    }
};

// USING DP
class Solution
{
private:
    int f(int ind, int prev, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }

        if (dp[ind][prev + 1] != -1)
        {
            return dp[ind][prev + 1];
        }

        int notTake = 0 + f(ind + 1, prev, nums, n, dp);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev])
        {
            take = 1 + f(ind + 1, ind, nums, n, dp);
        }

        return dp[ind][prev + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};