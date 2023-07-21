// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {

        priority_queue<double> q;

        double sum = 0.0;

        for (auto it: nums) {
            sum += it;
            q.push(it);
        }
        int count = 0;
        double curr = 0.0;

        while(curr < sum/2.0) {
            auto it = q.top();
            q.pop();

            double m = it/2.0;
            q.push(m);
            count++;
            curr += m;
        }

        return count;
    }
};