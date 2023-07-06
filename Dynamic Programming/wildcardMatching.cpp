// https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool f(int i, int j, string &s, string &p)
    {
        // base case
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || s[i] == '?')
        {
            return f(i - 1, j - 1, s, p);
        }
        if (s[i] == '*')
        {
            return f(i - 1, j, s, p) || f(i, j - 1, s, p);
        }

        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        return f(m - 1, n - 1, p, s);
    }
};

// MEMOISATION
class Solution
{
private:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == p[j] || s[i] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }
        if (s[i] == '*')
        {
            return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);
        }

        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, p, s, dp);
    }
};