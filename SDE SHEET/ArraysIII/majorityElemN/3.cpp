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

// optimal approach
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	vector<int> ans;
	int n = v.size();
	
	int el1 = -1e9;
	int el2 = -1e9;
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 0; i < n; i++) {
		if (cnt1 == 0 && el2 != v[i]) {
			cnt1 = 1;
			el1 = v[i];
		}
		else if (cnt2 == 0 && el1 != v[i]) {
			cnt2 = 1;
			el2 = v[i];
		}
		else if (el1 == v[i]) {
			cnt1++;
		}
		else if (el2 == v[i]) {
			cnt2++;
		}
		else {
			cnt1--;
			cnt2--;
		}
	}
	
	cnt1 = 0;
	cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (el1 == v[i]) {
			cnt1++;
		}
		if (el2 == v[i]) {
			cnt2++;
		}
	}
	if (cnt1 >= int(n/3) + 1) {
		ans.push_back(el1);
	}
	if (cnt2 >= int(n/3) + 1) {
		ans.push_back(el2);
	}

	return ans;
}