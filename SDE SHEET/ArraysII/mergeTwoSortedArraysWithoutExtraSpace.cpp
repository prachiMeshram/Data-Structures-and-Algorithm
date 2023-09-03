// https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;
#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.

	int n = a.size();
	int m = b.size();
	
	int l = n-1;
	int r = 0;

	while (l>=0 && r<m) {
		if (a[l] > b[r]) {
			swap(a[l--], b[r++]);
		}
		else if (a[l] <= b[r]){
			break;
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}