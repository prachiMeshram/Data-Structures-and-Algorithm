// https://www.codingninjas.com/studio/problems/partition-array-for-maximum-sum_3755255?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
using namespace std;

int f(int i, vector<int> &arr, int k) {
    int n = arr.size();

    if (i == n) {
        return 0;
    }
    int len = 0;
    int maxSum = INT_MIN;
    int maxi = INT_MIN;

    for (int j = i; j < min(i+k, n); j++) {
        len++;
        maxi = max(maxi, arr[j]);

        maxSum = max(maxSum, maxi*len + f(j+1, arr, k));
    }

    return maxSum;
}

int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.

    return f(0, arr, k);
}

// MEMOISATION

int f(int i, vector<int> &arr, int k, vector<int> &dp) {
    int n = arr.size();

    if (i == n) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    int len = 0;
    int maxSum = INT_MIN;
    int maxi = INT_MIN;

    for (int j = i; j < min(i+k, n); j++) {
        len++;
        maxi = max(maxi, arr[j]);

        maxSum = max(maxSum, maxi*len + f(j+1, arr, k, dp));
    }

    return maxSum;
}

int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(0, arr, k, dp);
}

// TABULATION

int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n+1, 0);

    for (int i = n-1; i >= 0; i--) {
        int len = 0;
        int maxSum = INT_MIN;
        int maxi = INT_MIN;
        for (int j = i; j < min(i+k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);

            maxSum = max(maxSum, maxi*len + dp[j+1]);
        }

        dp[i] = maxSum;
    }

    return dp[0];
}