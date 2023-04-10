// https://www.interviewbit.com/problems/count-element-occurence/

#include<bits/stdc++.h>
using namespace std;

void binarySearch (int s, int e, const vector<int> &A, int B, int &ans) {
    if (s>e) {
        return;
    }
    int mid = (s + (e-s)/2);
    if (A[mid] == B) {
        ans++;
        binarySearch(mid+1, e, A, B, ans);
        binarySearch(s, mid-1, A, B, ans);
    }
    else if (A[mid] < B) {
        binarySearch(mid+1, e, A, B, ans);
    }
    else {
        binarySearch(s, mid-1, A, B, ans);
    }
}

int findCount(const vector<int> &A, int B) {
    
    int ans = 0;
    int s = 0;
    int e = A.size()-1;
    
    binarySearch (s, e, A, B, ans);
    
    return ans;
}
