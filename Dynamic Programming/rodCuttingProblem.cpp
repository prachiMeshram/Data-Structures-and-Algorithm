// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// recursion
int fun(int ind, int N, vector<int> &price) {
	if (ind == 0) {
		return price[0]*N;
	}

	int notTake = 0 + fun (ind-1, N, price);

	int take = INT_MIN;
	int rodLen = ind+1;
	if (rodLen <= N) {
		take = price[ind] + fun(ind, N - rodLen, price);
	}

	return  max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	
	return fun(price.size() -1, n, price);
}
