// https://www.codingninjas.com/studio/problems/1112652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// BRUTE FORCE 
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] > 2* arr[j]) {
				count++;
			}
		}
	}

	return count;
}

// merge sort
#include <bits/stdc++.h> 

void merge(vector<int> &arr, int s, int e) {
	int m = s + (e-s)/2;
	vector<int> temp;
	int l = s;
	int r = m+1;

	while (l <= m && r <= e) {
		if (arr[r] < arr[l]) {
			temp.push_back(arr[r++]);
		}
		else {
			temp.push_back(arr[l++]);
		}
	}

	while (l <= m) {
		temp.push_back(arr[l++]);
	}
	while (r <= e) {
		temp.push_back(arr[r++]);
	}

	for (int i = s; i <= e; i++) {
		arr[i] = temp[i-s];
	}
}

int countRevPairs(vector<int> &arr, int s, int e) {
	int cnt = 0;
	int m = s + (e-s)/2;
	int r = m+1;
	
	for (int i = s; i <= m; i++) {
		while (r <= e && arr[i] > 2 * arr[r]) {
			r++;
		} 
		cnt += (r-(m+1));
	}

	return cnt;
}

int mergeSort(vector<int> &arr, int s, int e) {
	int cnt = 0;
	if (s >= e) {
		return cnt;
	}
	int m = s + (e-s)/2;
	cnt += mergeSort(arr, s, m); 
	cnt += mergeSort(arr, m+1, e);
	cnt += countRevPairs(arr, s, e);
	merge(arr, s, e);
	
	return cnt;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	
	mergeSort(arr, 0, n-1);
}