// https://www.codingninjas.com/studio/problems/palindrome-partitioning_626181?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome (string &s, int st, int ed) {
    while (st <= ed) {
        if (s[st] != s[ed]) {
            return false;
        }
        st++;
        ed--;
    }
    return true;
}

void solve (int ind, vector<string> &ds, vector<vector<string>> &ans, string s) {
    if (ind == s.size()) {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < s.size(); i++) {
        if (isPalindrome(s, ind, i)) {
            ds.push_back(s.substr(ind, i-ind+1));
            solve(i+1, ds, ans, s);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> ds;
    solve(0, ds, ans, s);

    return ans;
}
