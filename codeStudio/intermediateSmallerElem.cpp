#include <bits/stdc++.h> 
int* immediateSmaller(int* arr, int n) 
{
	// WRITE YOUR CODE HERE
	int* ans = new int[n]; 
	for(int i = 0; i < n-1; i++) {
		if(arr[i+1]<arr[i]) {
			ans[i] = arr[i+1];
		}
		else {
			ans[i] = -1;
		}
	}
	ans[n-1] = -1;
	return ans;
}
