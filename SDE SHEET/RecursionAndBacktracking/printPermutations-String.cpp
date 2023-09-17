// https://www.codingninjas.com/studio/problems/758958?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

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