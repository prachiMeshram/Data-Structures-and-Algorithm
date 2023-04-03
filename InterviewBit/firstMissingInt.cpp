
// https://www.interviewbit.com/problems/first-missing-integer/
#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    
    int maxi = INT_MIN;
    
    for (int i= 0; i < A.size(); i++) {
        if (A[i] > maxi ) {
            maxi = A[i];
        }
    }
    
    int temp[maxi+1] = {0};
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i]>0) {
            temp[A[i]]++;
        }
    }
    
    for (int i = 1; i< A.size() + 1; i++) {
        if (temp[i] == 0) {
            return i;
        }
    }    
    return maxi+1;
}
