// https://leetcode.com/contest/weekly-contest-359/problems/find-the-longest-equal-subarray/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {

        int n = nums.size();
        map<int, int> mpp;
        int ans = 0;
        int sum = 0;
        int mx = 0;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            sum += 1;
            mx = max(mx, mpp[nums[i]]);
            ans = max(ans, mx);

            while (sum - mx > k)
            {
                mpp[nums[j]]--;
                sum--;
                mx = max(mx, mpp[nums[j]]);
                j++;
            }
        }
        return ans;
    }
};