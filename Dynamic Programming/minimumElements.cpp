// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries

#include <bits/stdc++.h> 
using namespace std;


// recursion
int fun (int ind, int T, vector<int> &num) {
    // base case 
    if (ind == 0) {
        if (T%num[0] == 0) {
            return T/num[0];
        }
        else {
            return 1e9;
        }
    }
    
    int notTake = 0 + fun (ind-1, T, num);
    int take = INT_MAX;
    if (T>=num[ind]) {
        take = 1 + fun(ind, T-num[ind], num);
    }
    
    return min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    
    int ans =  fun(n-1, x, num);

    if (ans >= 1e9) {
        return -1;
    }
    return ans;
}

// recursion with DP
#include <bits/stdc++.h> 
int fun (int ind, int T, vector<int> &num, vector<vector<int>> &dp) {
    // base case 
    if (ind == 0) {
        if (T%num[0] == 0) {
            return T/num[0];
        }
        else {
            return 1e9;
        }
    }

    if (dp[ind][T] != -1) {
        return dp[ind][T];
    }
    
    int notTake = 0 + fun (ind-1, T, num, dp);
    int take = INT_MAX;
    if (T>=num[ind]) {
        take = 1 + fun(ind, T-num[ind], num, dp);
    }
    
    return dp[ind][T] = min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp (n, vector<int> (x+1, -1));
    int ans =  fun(n-1, x, num, dp);

    if (ans >= 1e9) {
        return -1;
    }
    return ans;
}


// TABULATION 
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    int T = x;
    vector<vector<int>> dp (n, vector<int> (T+1, 0));

    for (int tar = 0; tar <= T; tar++) {
        if (tar%num[0] == 0) {
            dp[0][tar] = tar/num[0];
        }
        else {
            dp[0][tar] = 1e9;
        }
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= T; tar++) {

            int notTake = 0 + dp[ind-1][tar];

            int take = 1e9;
            if (tar>=num[ind]) {
                take = 1 + dp[ind][tar-num[ind]];
            }
    
            dp[ind][tar] = min(take, notTake);
        }
    }


    int ans =  dp[n-1][T];

    if (ans >= 1e9) {
        return -1;
    }
    return ans;
}
