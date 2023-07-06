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

// TABULATION
class Solution
{

public:
    bool isMatch(string s, string p)
    {
        string s1 = p;
        string s2 = s;

        int n = s1.size();
        int m = s2.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (s1[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (s1[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

// SPACE OPTIMISATION

class Solution
{

public:
    bool isMatch(string s, string p)
    {
        string s1 = p;
        string s2 = s;

        int n = s1.size();
        int m = s2.size();

        vector<bool> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = true;

        for (int j = 1; j <= m; j++)
        {
            prev[j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (s1[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++)
            {

                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (s1[i - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};