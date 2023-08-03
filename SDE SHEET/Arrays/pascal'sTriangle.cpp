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