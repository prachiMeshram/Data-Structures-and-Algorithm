// https://www.interviewbit.com/problems/mathbug02/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> squareSum(int A) {
    
    vector<vector<int> > ans;
    
    if (A==1) {
        return ans;
    }
	
	for (int a = 0; a * a < A; a++) {
		for (int b = 0; b * b < A; b++) {
			if ((a * a + b * b == A && (a<=b))) {
				vector<int> newEntry; 
				newEntry.push_back(a);
				newEntry.push_back(b);
				ans.push_back(newEntry);
			}
		}
	}
	return ans;
}
