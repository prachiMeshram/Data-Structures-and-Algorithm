// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int> &arr) {
    if (i==j) {
        return 0;
    }

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int steps = f(i, k, arr) + f(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini, steps);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return f(1, N-1, arr);
}