// https://www.interviewbit.com/problems/allocate-books/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int> &A, int n, int B) {
    int stuCount = 1;
    int pgCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (pgCount + A[i] <= mid) {
            pgCount += A[i];
        }
        else {
            stuCount++;
            if (stuCount > B || A[i] > mid) {
                return false;
            }
            pgCount = A[i];
        }
    } 
    return true;
}

int books(vector<int> &A, int B) {
    int n = A.size();
    
    if (n<B) {
        return -1;
    }
    
    int maxi = A[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i]>maxi) {
            maxi = A[i];
        }
        sum += A[i]; 
    }
    
    
    int s = maxi;
    int e = sum;
    int ans;
    
    while ( s <= e) {
        int mid = s + (e-s)/2;
        if (isPossible(mid, A, n, B)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return ans;
}
