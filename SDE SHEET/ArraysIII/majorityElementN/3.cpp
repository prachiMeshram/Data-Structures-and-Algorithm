// https://www.codingninjas.com/studio/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE 
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	vector<int> ans;
	int n = v.size();
	int mini = int(n/3) + 1;

	for (int i = 0; i < n; i++) {
		
		if (ans.size() == 0 || ans[0] != v[i]) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (v[i] == v[j]) {
					cnt++;
				}
			}
			
			if (cnt > (n/3)) {
				ans.push_back(v[i]);
			}
		}
		if (ans.size() == 2) {
			break;
		}
	}	
	sort(ans.begin(), ans.end());
	return ans;
}

// better approach
vector<int> majorityElement(vector<int> v) {
	// Write your code here

	vector<int> ans;

	map<int, int> mpp;
	int n = v.size();
	int mini = int(n/3) + 1;

	for (int i = 0; i < n; i++) {
		mpp[v[i]]++;
		if (mpp[v[i]] == mini) {
			ans.push_back(v[i]);
		}
		if (ans.size() == 2) {
			break;
		}
	}
	return ans;
}