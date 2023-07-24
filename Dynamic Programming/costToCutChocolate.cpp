// https://www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int> &cuts) {
    if (i>j) {
        return 0;
    }

    int mini = INT_MAX;
    for(int k = i; k <= j; k++) {
        int cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts) + f(k+1, j, cuts);
        mini = min(mini, cost);
    }

    return mini;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.

    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    return f(1, c, cuts);
}