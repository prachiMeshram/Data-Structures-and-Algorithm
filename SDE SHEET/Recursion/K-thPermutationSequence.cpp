// https://www.codingninjas.com/studio/problems/1112626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
using namespace std;

// OPTIMISED APPROACH
string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++) {
        fact *= i;
        nums.push_back(i); 
    }
    nums.push_back(n);
    string ans = "";
    k = k-1;

    while (true) {
        ans += to_string(nums[k/fact]);
        nums.erase(nums.begin() + k/fact);
        if (nums.size() == 0) {
            break;
        } 
        
        k = k%fact;
        fact = fact/nums.size();
    }
    return ans;
}

// USING RECURSION

void solve(int ind, vector<string> &res, string &s) {
    if (ind == s.size()) {
        res.push_back(s);
        return;
    }

    for (int i = ind; i < s.size(); i++) {
        swap(s[i], s[ind]);
        solve (ind+1, res, s);
        swap(s[i], s[ind]);
    } 
}
string kthPermutation(int n, int k) {
    // Write your code here.
    vector<string> res;
    string s;
    
    for (int i = 1; i <= n; i++) {
        s.push_back(i+'0');
    }
    
    solve(0, res, s);
    
    sort(res.begin(), res.end());
    
    auto it = res.begin() + (k-1);
    return *it;
}

