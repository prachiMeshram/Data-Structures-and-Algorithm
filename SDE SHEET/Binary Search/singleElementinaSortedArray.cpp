// https://www.codingninjas.com/studio/problems/1112654?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// optimised approach

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n = arr.size();
	int s = 0;
	int e = n-2;
	
	while (s<=e) {
		int m = s + (e-s)/2;
		if (arr[m] == arr[m^1]) {
			s = m+1;
		}
		else {
			e = m-1;
		}
	}
	return arr[s];
}