// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;


bool isPossible(int mid, vector<int> &stalls, int k, int n) {
    int cows = 1;
    int last = stalls[0];
    
    for (int i = 0; i < n; i++) {
        if (stalls[i]-last >= mid) {
            cows++;
            if (cows == k) return true;
            last = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int ans = -1;
    
    long long s = 1;
    long long e = stalls[n-1]-stalls[0];

    while (s <= e) {
        long long mid = s + (e-s)/2;
        if (isPossible(mid, stalls, k, n)) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }
    return ans;
}