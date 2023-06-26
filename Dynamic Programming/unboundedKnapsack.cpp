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
