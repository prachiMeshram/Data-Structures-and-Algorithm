// https://www.interviewbit.com/problems/prime-numbers/

#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int A) {
    vector<int> ans(A, 1);
    
    for (int i = 2; i <= A/2; i++) {
            int j = 2;
            while (j*i<A) {
                ans[i*j] = 0;
                j++;
            }
    }
    
    vector<int> res;
    
    for (int i = 2; i < A; i++) {
        if (ans[i] == 1) {
            res.push_back(i);
        }
    }
    
    return res;
}
