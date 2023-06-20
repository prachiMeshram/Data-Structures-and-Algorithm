// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // sort(num.begin(), num.end());


    int n = num.size();

    vector<int> prev(tar+1, 0);
    
    if (num[0] <= tar) {
        prev[num[0]] = 1;
    }
    if(num[0] == 0) {
        prev[0] = 2;
    }
    else {
        prev[0] = 1;
    }

    for (int i = 1; i < n; i++) {
        vector<int> curr(tar+1, 0);
        curr[0] = 1;
        for (int t = 0; t <= tar; t++) {

            int notTake = prev[t];

            int take = 0;
            if (num[i] <= t) {
                take = prev[t-num[i]];
            }

            curr[t] = take + notTake;
        }
        prev = curr;
    }

    return prev[tar];
}