// https://www.codingninjas.com/studio/problems/trapping-rain-water_630519?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

// BETTER SOLUTION
long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    vector<long long> prefix(n);
    vector<long long> suffix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i-1], arr[i]);
    }
    suffix[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long waterLvl = min(prefix[i], suffix[i]);
        ans += waterLvl-arr[i];
    }

    return ans;
}