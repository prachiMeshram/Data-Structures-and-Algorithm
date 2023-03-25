// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

int solve(vector<int> &A) {
    int maxi = INT_MIN;
    int mini = INT_MAX;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }
        else if (A[i] < mini) {
            mini = A[i];
        }
        else {
            continue;
        }
    }
    
    return maxi+mini;
}
