// https://www.codingninjas.com/studio/problems/759408?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &a, int num) {
    for (auto it: a) {
        if (num == it) {
            return true;
        }
    }
    return false;
}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int cnt = 1;

        while (linearSearch(arr, x+1) == 1) {
            x += 1;
            cnt += 1;
        }
        ans = max(ans, cnt);
    }

    return ans;
}