// https://www.interviewbit.com/problems/rotated-sorted-array-search/

#include<bits/stdc++.h>
using namespace std;

int search(const vector<int> &A, int B) {
    //either first elem is B or arr size is one
    if (A[0] == B) {
        return 0;
    }
    
    int n = A.size();
    
    int s = 1;
    int e = n-1;
    
    while (s<=e) {
        int mid = s + (e-s)/2;
        if (A[mid] == B) {
            return mid;
        }
        // this means B may lie in start of arr
        if (A[0] < B){
            // if mid lies in first part
            if (A[mid]<A[0] || A[mid]>B) {
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        else {
            if (A[mid]>A[0] || A[mid]<B) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
    }
    return -1;
}
