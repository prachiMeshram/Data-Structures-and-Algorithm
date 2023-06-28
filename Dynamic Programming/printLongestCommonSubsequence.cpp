// https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '$';
    }

    int ind = len - 1;
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[ind] = s[i - 1];
            ind--;
            i--;
            j--;
        }
        else if (dp[i - 1] > dp[j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << ans;
}

int main()
{

    string s1 = "abcde";
    string s2 = "bdgek";

    cout << "The Longest Common Subsequence is ";
    lcs(s1, s2);
}