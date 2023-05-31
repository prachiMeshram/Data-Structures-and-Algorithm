// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int solve (vector<int> &nums, int n, vector<int> &dp) {
    //MEMOIZATION

    if (n == 0) {
        return nums[0];
    }
    if (dp[n]!=-1) {
        return dp[n];
    }
    if (n < 0) {
        return 0;
    }

    // inlcude
    int include = nums[n] + solve(nums, n-2, dp);

    // exclude
    int exclude = solve(nums, n-1, dp);

    dp[n] = max(include, exclude);

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // TABULATION
    int n = nums.size();

    vector<int> dp(n, -1);
    dp[0] = nums[0];
    int neg = 0;

    for (int i = 0; i < n; i++) {
        int include = nums[i];
        if (i>1) {
            include += dp[i-2]; 
        }
        int exclude = dp[i-1];

        dp[i] = max(include, exclude);
    }

    return dp[n-1];
}

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.

    // optimised SPACE COMPLEXITY

//     int n = nums.size();
//     // vector<int> dp(n, -1);
//     // return solve(nums, n-1, dp);

//     int prev = nums[0];
//     int prev2 = 0;

//     for (int i = 1; i < n; i++) {

//         int include = nums[i];
//         if (i>1) {
//             include += prev2;
//         }
//         int exclude = prev;

//         int curri = max(include, exclude);
//         prev2 = prev;
//         prev = curri;
//     }

//     return prev;

// }