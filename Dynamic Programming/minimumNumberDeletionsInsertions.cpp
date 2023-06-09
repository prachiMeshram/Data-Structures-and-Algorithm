// https://codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// TABULATION
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str[i-1] == ptr[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = 0 + max ( dp[i-1][j],  dp[i][j-1]);
            }
        }
    }

    int lcs = dp[n][m];

    return n + m - 2 * lcs;
}

// SPACE OPTIMISATION
#include <bits/stdc++.h> 
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str[i-1] == ptr[j-1]) {
                curr[j] = 1 + prev[j-1];
            }
            else {
                curr[j] = 0 + max ( prev[j],  curr[j-1]);
            }
        }
        prev = curr;
    }

    int lcs = prev[m];

    return n + m - 2 * lcs;
}