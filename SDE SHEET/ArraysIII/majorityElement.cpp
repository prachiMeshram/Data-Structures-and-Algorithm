// https://www.codingninjas.com/studio/problems/majority-element_6783241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


#include<bits/stdc++.h>
// hashing
int majorityElement(vector<int> v) {
	// Write your code here
	int n = v.size();
	map<int, int> mpp;
	
	for (int i = 0; i < n; i++) {
		mpp[v[i]]++;
	}

	for (auto it: mpp) {
		if (it.second > n/2) {
			return it.first;
		} 
	}
}