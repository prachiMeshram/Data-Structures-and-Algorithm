// https://www.codingninjas.com/studio/problems/majority-element_6783241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


#include<bits/stdc++.h>
using namespace std;

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

#include<bits/stdc++.h>
// moore voting algo
int majorityElement(vector<int> v) {
	// Write your code here
	int n = v.size();
	int cnt = 0;
	int elem;

	for (int i = 0; i < n; i++) {
		if (cnt == 0) {
			cnt = 1;
			elem = v[i];
		}
		else if (v[i] == elem) {
			cnt++;
		}
		else if (v[i] != elem){
			cnt--;
		}
	}
	if (cnt) {
		return elem;
	}
}