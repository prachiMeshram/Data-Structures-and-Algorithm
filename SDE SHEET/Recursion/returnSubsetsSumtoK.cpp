// https://www.codingninjas.com/studio/problems/759331?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// Iterative and Bitmasking
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    
    for (int i = 0; i < pow(2, n); i++) {
        vector<int> ds;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                sum += arr[j];
                ds.push_back(arr[j]);
            }
        }
        if (sum == k) {
            ans.push_back(ds);
        }
    }
    return ans;
}

// recursive brute force
void solve(int i, vector<vector<int>> &ans, vector<int> ds, vector<int> arr, int n, int k) {
    if (i == n) {
        if (k == 0) {
            ans.push_back(ds);
        }
        return;
    }
    

    // take
    // if (arr[i] <= k) {
        
    // }
    ds.push_back(arr[i]);
    solve( i+1, ans, ds, arr, n, k-arr[i]);
    ds.pop_back();
    
    // notTake
    solve( i+1, ans, ds, arr, n, k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    solve (0, ans, ds, arr, n, k);
    return ans;
}