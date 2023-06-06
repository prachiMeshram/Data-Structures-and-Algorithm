// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    private:
    
    vector<int> nextSmallest(int *heights, int n) {
        vector<int> ans(n);

        stack<int> st;
        st.push(-1);

        for(int i = n-1; i>=0; i--) {
            int curr = heights[i];

            while (st.top()!=-1 && heights[st.top()] >= curr) 
            {
                st.pop();
            } 
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallest(int *heights, int n) {
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

    int largestRectangleArea(int *heights, int n) {

        // int n = heights.size();

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
    
    public:
      int maxArea(int M[MAX][MAX], int n, int m) {
          // Your code here
          int area = largestRectangleArea(M[0], m);
          
          for(int i = 1; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  
                  if (M[i][j] != 0) {
                      M[i][j] += M[i-1][j]; 
                  }
                  else {
                      M[i][j] = 0;
                  }
              }
              area = max( area, largestRectangleArea(M[i], m) );
          }
          return area;
      }
};