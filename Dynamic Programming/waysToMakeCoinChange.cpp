// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// recursion with dp
long totWays(int ind, int T, int *d, vector<vector<long>> &dp) {
    // base case
    if (ind == 0) {
        return T%d[0] == 0;
    }

    if (dp[ind][T] != -1) {
        return dp[ind][T];
    }

    long notTake = totWays(ind-1, T, d, dp);

    long take = 0;
    if (d[ind] <= T) {
        take = totWays(ind, T - d[ind], d, dp);
    }

    return dp[ind][T] = take + notTake;
} 

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value+1, 0));


    // TABULATION
    for (int tar = 0; tar <= value; tar++) {
        dp[0][tar] = (tar%denominations[0] == 0);
    }
    
    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= value; tar++) {
            long notTake = dp[ind-1][tar];

            long take = 0;
            if (denominations[ind] <= tar) {
                take = dp[ind][tar - denominations[ind]];
            }

            dp[ind][tar] = take + notTake;
        }
    }

    return dp[n-1][value];
}

// SPACE OPTIMISATION
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<long> prev(value+1, 0), curr(value+1, 0);

    for (int tar = 0; tar <= value; tar++) {
        prev[tar] = (tar%denominations[0] == 0);
    }
    
    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= value; tar++) {
            long notTake = prev[tar];

            long take = 0;
            if (denominations[ind] <= tar) {
                take = curr[tar - denominations[ind]];
            }

            curr[tar] = take + notTake;
        }
        prev = curr;
    }

    return prev[value];
}