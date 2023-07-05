// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h> 
using namespace std;

// RECURSION

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

// DP 
class Solution {
private: 
    int s(int i, int j, string& w1, string& w2, vector<vector<int>> dp) {
        // base case
        if (i < 0) {
            return j+1;
        }
        if (j < 0) {
            return i+1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (w1[i] == w2[j]) {
            return dp[i][j] =  0 + s(i-1, j-1, w1, w2, dp);
        }
        else {
            // insert | delete | replace
            return dp[i][j] =  1 + min( s(i, j-1, w1, w2, dp), min( s(i-1, j, w1, w2, dp), s(i-1, j-1, w1, w2, dp) ));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return s(n-1, m-1, word1, word2, dp);
    }
};

// TABULATION
class Solution {
private: 
    int s(int i, int j, string& w1, string& w2, vector<vector<int>> dp) {
        // base case
        if (i < 0) {
            return j+1;
        }
        if (j < 0) {
            return i+1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (w1[i] == w2[j]) {
            return dp[i][j] =  0 + s(i-1, j-1, w1, w2, dp);
        }
        else {
            // insert | delete | replace
            return dp[i][j] =  1 + min( s(i, j-1, w1, w2, dp), min( s(i-1, j, w1, w2, dp), s(i-1, j-1, w1, w2, dp) ));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string w1 = word1 ;
        string w2 = word2 ;   

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (w1[i-1] == w2[j-1]) {
                     dp[i][j] =  0 + dp[i-1][j-1];
                }
                else {
                    // insert | delete | replace
                     dp[i][j] =  1 + min( dp[i][j-1], min( dp[i-1][j], dp[i-1][j-1]));
                }
            } 
        }

        return dp[n][m];
    }
};

// SPACE OPT
class Solution {
private: 
    int s(int i, int j, string& w1, string& w2, vector<vector<int>> dp) {
        // base case
        if (i < 0) {
            return j+1;
        }
        if (j < 0) {
            return i+1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (w1[i] == w2[j]) {
            return dp[i][j] =  0 + s(i-1, j-1, w1, w2, dp);
        }
        else {
            // insert | delete | replace
            return dp[i][j] =  1 + min( s(i, j-1, w1, w2, dp), min( s(i-1, j, w1, w2, dp), s(i-1, j-1, w1, w2, dp) ));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string w1 = word1 ;
        string w2 = word2 ;   

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (w1[i-1] == w2[j-1]) {
                     curr[j] =  0 + prev[j-1];
                }
                else {
                    // insert | delete | replace
                     curr[j] =  1 + min( curr[j-1], min( prev[j], prev[j-1]));
                }
            } 
            prev = curr;
        }

        return prev[m];
    }
};