// https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h> 
using namespace std;

// MY SOL
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        vector<int> prev(1, 1);
        ans.push_back(prev);
        
        for (int i = 1 ; i < numRows; i++) {
            vector<int> curr;
            curr.push_back(1);

            for (int j = 0; j+1 < prev.size(); j++) {
                curr.push_back(prev[j]+prev[j+1]);
            }

            curr.push_back(1);
            ans.push_back(curr);
            prev = curr;
        }

        return ans;
    }
};

// using combinations
class Solution {
public:
    int nCr(int r, int c) {
        int res = 1;

        for (int i = 0 ; i < c; i++) {
            res *= (r-i);
            res /= (i+1);
        }
        return res;
    }

    vector<int> getNthRow(int r) {
        vector<int> temp;
        int res = 1;
        for (int c = 1;  c <= r; c++) {
            temp.push_back(nCr(r-1, c-1));
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> row;
        
        for (int r = 1; r <= numRows; r++) {
            vector<int> row = getNthRow(r);
            ans.push_back(row);
        }

        return ans;
    }
};