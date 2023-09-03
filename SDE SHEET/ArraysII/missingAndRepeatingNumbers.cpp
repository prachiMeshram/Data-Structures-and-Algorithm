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

// USING XOR Operator

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	
	int xr = 0;
	for (int i = 0; i < n; i++) {
		xr ^= arr[i];
		xr ^= i+1;
	}
	int bitNum = 0;
	while (1) {
		if(xr & 1<<bitNum) {
			break;
		}
		bitNum++;
	}

	int zeroC = 0;
	int oneC = 0;
	
	for (int i = 0; i < n; i++) {
		// oneClub
		if (arr[i] & (1 << bitNum)) {
			oneC ^= arr[i];
		}
		else {
			zeroC ^= arr[i];
		}
	}
	for (int i = 0; i <= n; i++) {
		// oneClub
		if (i & 1 << bitNum) {
			oneC ^= i;
		}
		else {
			zeroC ^= i;
		}
	}
	int cnt = 0;
	for (auto it: arr) {
		if (it == oneC) {
			cnt++;
		}
	}
	if (cnt == 2) {
		return {zeroC, oneC};
	}
	else {
		return {oneC, zeroC};
	}
}

