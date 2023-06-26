// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// RECURSION
int fun(int ind, int w, vector<int> &profit, vector<int> &weight) {
    // base case 
    if (ind == 0) {
        return (w/weight[0])* profit[0];
    }

    int notTake = 0 + fun(ind-1, w, profit, weight);
    int take = INT_MIN;
    if (weight[ind] <= w) {
        take = profit[ind] + fun(ind, w - weight[ind], profit, weight);
    }

    return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.

    return fun(n-1, w, profit, weight);
}

// #include <bits/stdc++.h> 

// USING DP
int fun(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    // base case 
    if (ind == 0) {
        return (w/weight[0])* profit[0];
    }
    if (dp[ind][w] != -1) {
        return dp[ind][w];
    }

    int notTake = 0 + fun(ind-1, w, profit, weight, dp);
    int take = INT_MIN;
    if (weight[ind] <= w) {
        take = profit[ind] + fun(ind, w - weight[ind], profit, weight, dp);
    }

    dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp (n, vector<int> (w+1, -1));

    return fun(n-1, w, profit, weight, dp);
}

// #include <bits/stdc++.h> 

// TABULATION
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp (n, vector<int> (w+1, 0));
    

    for (int wt = weight[0]; wt <= w; wt++) {
        dp[0][wt] = ((int) wt / weight[0]) * profit[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {

            int notTake = 0 + dp[ind-1][wt];
            int take = INT_MIN;
            if (weight[ind] <= wt) {
                take = profit[ind] + dp[ind][wt - weight[ind]];
            }

            dp[ind][wt] = max(take, notTake);
        }
    }

    return dp[n-1][w];
}


