// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n);

    stack<int> st;
    st.push(-1);

    // [2, 5, 3, 4, 1]

    for (int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        while (st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}