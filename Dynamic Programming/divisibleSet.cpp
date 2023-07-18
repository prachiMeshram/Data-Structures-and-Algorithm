// https://www.codingninjas.com/studio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> hash(n);
    vector<int> dp(n, 1);

    int maxi = -11;
    int lastInd = -1;

    for (int i = 0; i < n; i++) {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] % arr[prev] == 0 && dp[i] < 1 + dp[prev]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastInd = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastInd]);

    while (hash[lastInd] != lastInd) {
        lastInd = hash[lastInd];
        temp.push_back(arr[lastInd]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}