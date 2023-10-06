// https://leetcode.com/contest/weekly-contest-361/problems/count-of-interesting-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        unordered_map<int, int> mpp;
        int n = nums.size();
        long long ans = 0;
        mpp[0] = 1;
        int prefixRem = 0;
        for (int i = 0; i < n; i++) {
            prefixRem = (prefixRem + ((nums[i] % modulo == k) ? 1 : 0)) % modulo;
            int target = (prefixRem - k + modulo) % modulo;
            ans += mpp[target];
            mpp[prefixRem]++;
        }
        return ans;
    }
};