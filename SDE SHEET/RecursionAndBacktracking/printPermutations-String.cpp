// https://www.codingninjas.com/studio/problems/758958?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// Using Recursion

void solve (string &st, vector<string> &ans, vector<int> &mpp, string &s) {
    if (st.size() == s.size()) {
        ans.push_back(st);
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (!mpp[i]) {
            mpp[i] = 1;
            st.push_back(s[i]);
            solve(st, ans, mpp, s);
            st.pop_back();
            mpp[i] = 0;
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    string st;
    int n = s.size();
    vector<int> mpp(n, 0);
    solve (st, ans, mpp, s);
    
    return ans;
}

// using backtracking
void solve (int ind, string &s, vector<string> &res) {
    if (ind == s.size()) {
        res.push_back(s);
        return;
    }

    for (int i = ind; i < s.size(); i++) {
        swap(s[ind], s[i]);
        solve(ind+1, s, res);
        swap(s[ind], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> res;
    solve(0, s, res);
    return res;
}