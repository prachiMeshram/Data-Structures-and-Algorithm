// https://www.codingninjas.com/studio/problems/1102307?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE USING SETS
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	set<int> st;
	
	for (auto it: arr) {
		st.insert(it);
	}
	
	int i = 0;
	for (auto it: st) {
		arr[i] = it;
		i++;
	}

	return i;
}

// OPTIMAL APPROACH USING TWO POINTERS

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i = 0;
	
	for (int j = 1; j < n; j++) {
		if (arr[i] != arr[j]) {
			arr[i+1] = arr[j];
			i++;
		}
	}

	return i+1;
}