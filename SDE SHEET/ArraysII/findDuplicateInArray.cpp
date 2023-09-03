// https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i+1]) {
			return arr[i];
		}
	}
}
