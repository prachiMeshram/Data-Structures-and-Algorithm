// https://www.interviewbit.com/problems/rearrange-array/discussion/p/no-extra-memeory-c/260029/897/

#include<bits/stdc++.h>
using namespace std;

void arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    for(int i = 0; i < n; i++) {
        A[i] += (A[A[i]]%n)*n;
    }
    
    for (int i = 0; i < n; i++) {
        A[i] = A[i]/n;
    }
    
    // wrong approach
    // for (int i = 0; i < A.size(); i++) {
    //     int temp = A[i];
    //     A[i] = A[A[i]];
    //     A[A[i]] = temp;
    // }
    // return;
}