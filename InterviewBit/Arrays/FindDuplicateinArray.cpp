// https://www.interviewbit.com/problems/find-duplicate-in-array/

#include <bits/stdc++.h> 
using namespace std;

int repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[0];
    
    do{
        slow = A[slow];
        fast = A[A[fast]];
    } while (slow!=fast);
    
    fast = A[0];
    while (fast!=slow) {
        slow = A[slow];
        fast = A[fast];
    }

    
    return (slow<0 ? -1 : slow);
}
