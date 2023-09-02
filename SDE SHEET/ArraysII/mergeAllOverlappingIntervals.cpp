// https://www.codingninjas.com/studio/problems/merge-all-overlapping-intervals_6783452?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;
#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> ans;
	vector<int> temp = arr[0];

	for (int i = 1; i < n; i++) {
		if (temp[1] >= arr[i][0] && temp[1] < arr[i][1]) {
			temp[1] = arr[i][1];
		}
		else if (temp[1] >= arr[i][0] && temp[1] >= arr[i][1]) {
			continue;
		}
		else {
			ans.push_back(temp);
			temp = arr[i];
		}
	}

	ans.push_back(temp);

	return ans;
}