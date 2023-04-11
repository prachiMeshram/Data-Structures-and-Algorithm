// https://www.interviewbit.com/problems/search-for-a-range/

#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(const vector<int> &A, int B) {
    vector<int> ans;
    int n = A.size();
    pair<int,int> temp = {-1, -1};
    
    int s = 0; 
    int e = n-1;
    int mid = s + (e-s)/2;
    
    // for first element 
    while (s <= e) {
        if (A[mid] == B) {
            temp.first = mid;
            e = mid-1;
        }
        else if (A[mid]< B) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    
    // for second element 
    s = 0; 
    e = n-1;
    mid = s + (e-s)/2;
    while (s <= e) {
        if (A[mid] == B) {
            temp.second = mid;
            s = mid+1;
        }
        else if (A[mid]< B) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    ans.push_back(temp.first);
    ans.push_back(temp.second);
    
    return ans;
}
