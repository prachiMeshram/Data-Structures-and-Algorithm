// https://www.interviewbit.com/problems/rotated-array/

#include<bits/stdc++.h>
using namespace std;

int findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    
    while (s<=e) {
        if(A[mid] < A[mid-1] && A[mid] < A[mid+1]) {
            return A[mid];
        }
        else if (A[mid]>A[e]){
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return A[mid];
}
