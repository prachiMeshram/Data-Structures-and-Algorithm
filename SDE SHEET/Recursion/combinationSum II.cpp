// https://www.codingninjas.com/studio/problems/1112622?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// recursive approach 
void solve (int i, int target, vector<int> &dp, vector<vector<int>> &ans, vector<int> &arr, int n) {
	if (target == 0) {
		ans.push_back(dp);
		return;
	}

	for (int j = i; j < n; j++) {
		if (j > i && arr[j] == arr[j-1]) continue;
		if (arr[j] > target ) break;

		dp.push_back(arr[j]);
		solve(j+1, target-arr[j], dp, ans, arr, n);
		dp.pop_back(); 
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>> ans;
	vector<int> dp;
	sort(arr.begin(), arr.end());
	solve (0, target, dp, ans, arr, n);
	return ans;
}
