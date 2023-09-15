// https://www.codingninjas.com/studio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<int> &nums, vector<int> &ans, int sum) {
	if (i == nums.size()) {
		ans.push_back(sum);
		return;
	}
	// pick
	solve(i+1, nums, ans, sum+nums[i]);
	// not pick
	solve(i+1, nums, ans, sum);
}

vector<int> subsetSum(vector<int> &nums){
	// Write your code here.
	vector<int> ans;
	solve(0, nums, ans, 0);
	sort(ans.begin(), ans.end());
	return ans;
}

// using power set
vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	int n = num.size();
	vector<int> ans;
	
	for (int i = 0; i < (pow(2, n)); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) {
				sum += num[j];
			}
		}
		ans.push_back(sum);
	}
	sort(ans.begin(), ans.end());
	return ans;
}