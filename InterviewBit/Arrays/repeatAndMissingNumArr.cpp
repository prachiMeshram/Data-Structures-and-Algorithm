// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    pair<int, int> res;
    vector<int> sol;
    
    int n = A.size();
    int ans[n+1] = {0};
    
    for(int i = 0; i < n; i++) {
        ans[A[i]]++;
    }
    
    for (int i = 1; i < n+1; i++) {
        if (ans[i] == 2) {
            res.first = i;
        }
        if (ans[i] == 0) {
            res.second = i;
        }
    } 
    
    sol.push_back(res.first); 
    sol.push_back(res.second); 
    
    return sol;
}
