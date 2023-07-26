// https://www.codingninjas.com/studio/problems/boolean-evaluation_1214650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

#define ll long long

int mod = 1000000007;

int f(int i, int j, int isTrue ,string &exp) {
    if (i > j) {
        return 0;
    }

    if (i == j) {
        if (isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    ll nways = 0;
    for (int k = i + 1; k < j; k += 2 ) {

        ll lt = f(i, k-1, 1, exp);
        ll lf = f(i, k-1, 0, exp);
        ll rt = f(k+1, j, 1, exp);
        ll rf = f(k+1, j, 0, exp);

        if (exp[k] == '|') {
            if (isTrue) {
                nways = (nways + (lt*rf) % mod + (lf*rt)% mod + (lt*rt)% mod) % mod;
            }
            else {
                nways = (nways + (lf*rf)% mod) % mod;
            }
        }
        else if (exp[k] == '&') {
            if (isTrue) {
                nways = (nways + (lt*rt)% mod) % mod;
            }
            else {
                nways = (nways + (lt*rf)% mod + (lf*rt)% mod + (lf*rf)% mod) % mod;
            }
        }
        else {
            if (isTrue) {
                nways = (nways + (lt*rf)% mod + (lf*rt)% mod) % mod;
            }
            else {
                nways = (nways + (lt*rt)% mod + (lf*rf)% mod) % mod;
            }
        }
    }
    return nways;    
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();

    return f(0, n-1, 1, exp);
}

// MEMOISAION 
#include <bits/stdc++.h> 

#define ll long long

int mod = 1000000007;

int f(int i, int j, int isTrue ,string &exp, vector<vector<vector<int>>> &dp) {
    if (dp[i][j][isTrue] != -1) {
        return dp[i][j][isTrue];
    }

    if (i > j) {
        return 0;
    }

    if (i == j) {
        if (isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    
    ll nways = 0;
    for (int k = i + 1; k < j; k += 2 ) {

        ll lt = f(i, k-1, 1, exp, dp);
        ll lf = f(i, k-1, 0, exp, dp);
        ll rt = f(k+1, j, 1, exp, dp);
        ll rf = f(k+1, j, 0, exp, dp);

        if (exp[k] == '|') {
            if (isTrue) {
                nways = (nways + (lt*rf) % mod + (lf*rt)% mod + (lt*rt)% mod) % mod;
            }
            else {
                nways = (nways + (lf*rf)% mod) % mod;
            }
        }
        else if (exp[k] == '&') {
            if (isTrue) {
                nways = (nways + (lt*rt)% mod) % mod;
            }
            else {
                nways = (nways + (lt*rf)% mod + (lf*rt)% mod + (lf*rf)% mod) % mod;
            }
        }
        else {
            if (isTrue) {
                nways = (nways + (lt*rf)% mod + (lf*rt)% mod) % mod;
            }
            else {
                nways = (nways + (lt*rt)% mod + (lf*rf)% mod) % mod;
            }
        }
    }
    return nways;    
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));

    return f(0, n-1, 1, exp, dp);
}