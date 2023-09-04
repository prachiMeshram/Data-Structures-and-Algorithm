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