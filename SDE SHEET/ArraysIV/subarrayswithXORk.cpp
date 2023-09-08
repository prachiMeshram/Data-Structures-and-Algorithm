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

// optimal approach using MAPS
#include<bits/stdc++.h>

int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n = a.size();
    map<int, int> mpp;
    int xr = 0;
    int cnt = 0;
    mpp[xr] = 1;
    
    for (int i = 0; i < n; i++) {
        xr ^= a[i];
        int x = xr^b;
        
        if (mpp.find(x) != mpp.end()) {
            cnt += mpp[x];
        }
        mpp[xr]++;
    }
    
    return cnt;
}