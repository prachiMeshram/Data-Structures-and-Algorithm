// https://leetcode.com/problems/smallest-integer-divisible-by-k/submissions/922178218/

#include <bits/stdc++.h> 

int lengthOfNumber(int k)
{
	// Write your code here.
	// An = (A(n-1)*10) + 1;

	if (k&1==0 || k%5==0) {
		return -1;
	}

	int num = 0;
	for (int i = 1; i<=k; i++) {
		num = (num*10 + 1) % k;
		if (num == 0) {
			return i;
		}
	}

	return -1;
}