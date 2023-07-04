// https://leetcode.com/problems/distinct-subsequences/description/

#include <bits/stdc++.h> 
using namespace std;

class Solution {

public:
    int solve (int i, int j, string &s, string &t) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }

        if ( s[i] == t[j]) {
            return solve(i-1, j-1, s, t) + solve(i-1, j, s, t);
        }
        if (t[j] != s[i]){
            return solve(i-1, j, s, t);
        }
        return 0;
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        return solve(n-1, m-1, s, t);
    }
};