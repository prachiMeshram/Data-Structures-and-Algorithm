// https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

// brute force
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n = a.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int xr = 0;

        for (int j = i; j < n; j++) {
            xr ^= a[j];
            if (xr == b) {
                cnt++;
            }
        }
    }
    return cnt;
}