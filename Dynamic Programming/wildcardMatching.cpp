// https://leetcode.com/problems/wildcard-matching/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool f(int i, int j, string& s, string& p) {
        // base case
        if (i < 0 && j < 0) {
            return true;
        }
        if (i < 0 && j >= 0) {
            return false;
        }
        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (s[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || s[i] == '?') {
            return f(i-1, j-1, s, p);
        }
        if (s[i] == '*') {
            return f(i-1, j, s, p) || f(i, j-1, s, p);
        }

        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return f(m-1, n-1, p, s);
    }
};