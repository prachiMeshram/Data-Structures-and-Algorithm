// https://www.codingninjas.com/studio/problems/892994?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int l = 0;
    int zeros = 0;
    int maxlen = 0;

    for (int r = 0; r < n; r++) {
        if (arr[r] == 0) zeros++;
        while (zeros > k) {
            if (arr[l] == 0) zeros--;
            l++;
        }
        maxlen = max(maxlen, r-l+1);
    }
    return  maxlen;
}
