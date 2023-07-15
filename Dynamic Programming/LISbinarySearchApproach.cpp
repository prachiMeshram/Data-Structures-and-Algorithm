// https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}
