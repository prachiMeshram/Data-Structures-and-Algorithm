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

// using maths 
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int N)
{
	// Write your code here 
	// pair<int,int> ans;
	
	long long n = arr.size();
	
	long long Sn = (n*(n+1))/2;
	long long S2n = (n*(n+1)*(2*n+1))/6;
	
	long long S = 0;
	long long S2 = 0;
	for (auto it: arr) {
		S += it;
		S2 += (long long)it*(long long)it;
	}
	
	long long val1 = S-Sn; // x-y 
	long long val2 = S2-S2n;
	val2 = val2/val1; // x+y
	
	long long x = (val1+val2)/2;
	long long y = x - val1;

	return {(int)y, (int)x};
}
