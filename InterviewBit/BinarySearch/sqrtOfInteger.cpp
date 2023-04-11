// https://www.interviewbit.com/problems/square-root-of-integer/

#include<bits/stdc++.h>
using namespace std;

int sqrt(int A) {
    if (A==0) {
        return 0;
    }
    
    long int ans = 1;
    
    long int s = 1; 
    long int e = A;
    
    long int mid = s + (e-s)/2;
    
    while (s<e) {
        if (mid*mid == A) {
            return mid;
        }
        else if (mid*mid < A) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    
    return ans;
}
