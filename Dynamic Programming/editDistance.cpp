// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
private: 
    int s(int i, int j, string& w1, string& w2) {
        // base case
        if (i < 0) {
            return j+1;
        }
        if (j < 0) {
            return i+1;
        }

        if (w1[i] == w2[j]) {
            return 0 + s(i-1, j-1, w1, w2);
        }
        else {
            // insert | delete | replace
            return 1 + min( s(i, j-1, w1, w2), min( s(i-1, j, w1, w2), s(i-1, j-1, w1, w2) ));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return s(n-1, m-1, word1, word2);
    }
};