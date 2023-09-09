// https://www.codingninjas.com/studio/problems/630418?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int ans = 0;
    int n = input.size();
    unordered_map<char, int> mpp;
    int l = 0; 
    int r = 0;
    while (r<n) {
        
        if (mpp.find(input[r]) != mpp.end()) {
            l = max(mpp[input[r]]+1, l);
        }
        mpp[input[r]] = r;
        ans = max(r-l+1, ans);
        r++;
    }

    return ans;
}