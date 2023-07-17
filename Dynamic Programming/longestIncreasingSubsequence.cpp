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

// TABULATION
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // TABULATION
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0)) ;

        for (int ind = n-1; ind >= 0; ind--) {
            for (int prev = ind-1; prev >= -1; prev--) {
                int notTake = 0 + dp[ind+1][prev+1];
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + dp[ind+1][ind+1];
                } 
                dp[ind][prev+1] = max(take, notTake);
            }
        }

        return dp[0][-1+1];
    }
};

// SPACE OPT
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // TABULATION
        int n = nums.size();
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        for (int ind = n-1; ind >= 0; ind--) {
            for (int prev = ind-1; prev >= -1; prev--) {
                int notTake = 0 + next[prev+1];
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + next[ind+1];
                } 
                curr[prev+1] = max(take, notTake);
            }
            next = curr;
        }

        return next[-1+1];
    }
};