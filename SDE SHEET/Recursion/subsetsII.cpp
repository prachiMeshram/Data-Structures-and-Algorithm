// codingninjas.com/studio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

void solve (int ind, vector<vector<int>> &ans, vector<int> &dp, vector<int> &arr, int n) {
    ans.push_back(dp);
    
    for (int i = ind; i < n; i++) {
        if (i != ind && arr[i] == arr[i-1]) continue;
        dp.push_back(arr[i]);
        solve(i+1, ans, dp, arr, n);
        dp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> dp;
    
    sort(arr.begin(), arr.end());
    solve(0, ans, dp, arr, n);
    
    return ans;
}