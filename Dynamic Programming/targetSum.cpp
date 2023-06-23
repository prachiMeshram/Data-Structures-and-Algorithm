// https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

int findWays(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar+1, 0);

    if (arr[0] == 0) {
        prev[0] = 2;
    }
    else {
        prev[0] = 1;
    }

    if (arr[0] != 0 && arr[0] <= tar) {
        prev[arr[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++) {
        vector<int> curr(tar+1, 0);
        for (int t = 0; t <= tar; t++) {

            int notTake = 0 + prev[t];
            int take = 0;
            if (arr[ind] <= t) {
                take = prev[t-arr[ind]];
            }

            curr[t] = take + notTake;
        }
        prev = curr;
    }
    
    return prev[tar];
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    //Checking for edge cases
    if(sum-target <0 || (sum-target)%2 ) return 0;

    return findWays(arr, (sum-target)/2);
}
