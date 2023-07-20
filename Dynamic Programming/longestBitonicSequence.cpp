// https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0\

#include <bits/stdc++.h> 
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	 

	  vector<int> dp1(n, 1);

	  for (int i = 0; i < n; i++) {
		  for (int prev = 0; prev < i; prev++) {
			  if (arr[i] > arr[prev]) {
				  dp1[i] = max(dp1[i], 1 + dp1[prev]); 
			  }
		  }
	  } 

	  vector<int> dp2(n, 1);
	  int maxi = -1;
	  for (int i = n-1; i >= 0; i--) {
		  for (int prev = n-1; prev > i; prev--) {
			  if (arr[i] > arr[prev] ) {
				  dp2[i] = max(dp2[i], 1 + dp2[prev]); 
			  }
		  }
		  
		  maxi = max(maxi, dp1[i] + dp2[i] - 1);
	  }  

	  return maxi;
} 
