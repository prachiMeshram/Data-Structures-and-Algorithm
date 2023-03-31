//https://www.codingninjas.com/codestudio/problem-of-the-day/easy?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;
vector<int> multiply(vector<int> &a, vector<int> &b, int n){
    // Write your code here.
    vector<int> ans(2*a.size()-1);
    // if (n==1) {
    //     ans.push_back(a[0]*b[0]);
    //     return ans;
    // }

    for(int i = 0; i < a.size(); i++){

        int j = 0;
        while (j < b.size()) {
            ans[i+j] += a[i]*b[j];
            j++;
        }
    }

    return ans;
}