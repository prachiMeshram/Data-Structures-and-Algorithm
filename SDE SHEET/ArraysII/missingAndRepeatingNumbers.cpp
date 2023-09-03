// https://www.codingninjas.com/studio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// my solution
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int, int> ans;
	vector<int> count(n+1, 0);

	for (auto it: arr) {
		count[it]++;
		if(count[it]==2) {
			ans.second = it;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (count[i] == 0) {
			ans.first = i;
		}
	}

	return ans;
}