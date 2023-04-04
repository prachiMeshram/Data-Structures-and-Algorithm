// https://www.interviewbit.com/problems/maximum-consecutive-gap/

#include <bits/stdc++.h> 
using namespace std;

int maximumGap(const vector<int> &A) {
    
    if (A.size()==1) {
        return 0;
    }
    
    vector<int> B;
    for (int i = 0; i < A.size(); i++) {
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end());
    
    int diff = 0;
    for (int i = 1; i < B.size(); i++) {
        if (B[i]-B[i-1] > diff) {
            diff = B[i]-B[i-1];
        }
    }
    
    return diff;
}
