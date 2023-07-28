// https://www.codingninjas.com/studio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// MEMOISATION

bool isPalindrom(int i, int j, string &str) {
    while (i < j) {
        if (str[i] != str[j]) {
            return false; 
        }
        i++;
        j--;
    }
    return true;
}

int f(int i, string &str, int n, vector<int> dp) {

    if (dp[i] != -1) {
        return dp[i];
    }

    if (i == n){
        return 0;
    }

    int mini = INT_MAX;

    for (int j = i; j < n; j++) {
        if(isPalindrom(i, j, str)) {
            int cost = 1 + f(j+1, str, n, dp);
            mini = min(mini, cost);
        }
    }

    return dp[i] = mini;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n =str.size();

    vector<int> dp(n+1, -1);

    return f(0, str, n, dp) - 1;
}

//TABULATION

#include <bits/stdc++.h> 

bool isPalindrom(int i, int j, string &str) {
    while (i < j) {
        if (str[i] != str[j]) {
            return false; 
        }
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n =str.size();

    vector<int> dp(n+1, 0);

    for (int i = n-1; i >= 0; i--) {
        int mini = INT_MAX;

        for (int j = i; j < n; j++) {
            if(isPalindrom(i, j, str)) {
                int cost = 1 + dp[j+1];
                mini = min(mini, cost);
            }
        }

        dp[i] = mini;
    }

    return dp[0] - 1;
}
