// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallest(vector<int>& heights, int n) {
        vector<int> ans(n);

        stack<int> st;
        st.push(-1);

        for(int i = n-1; i>=0; i--) {
            int curr = heights[i];

            // [2, 5, 3, 4, 1]
            
            while (st.top()!=-1 && heights[st.top()] >= curr) 
            {
                st.pop();
            } 
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallest(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int curr = heights[i];

            while ( st.top()!= -1 && heights[st.top()] >= curr ) {
                st.pop();
            } 
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> next(n);
        next = nextSmallest(heights, n);

        vector<int> prev(n);
        prev = prevSmallest(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1) {
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            
            int currArea = l*b;
            area = max(area, currArea);
        }
        return area;
    }
};