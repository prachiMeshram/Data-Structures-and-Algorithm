// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries

#include <bits/stdc++.h> 
using namespace std;

int fun (int ind, int T, vector<int> &num) {
    // base case 
    if (ind == 0) {
        if (T%num[0] == 0) {
            return T/num[0];
        }
        else {
            return 1e9;
        }
    }
    
    int notTake = 0 + fun (ind-1, T, num);
    int take = INT_MAX;
    if (T>=num[ind]) {
        take = 1 + fun(ind, T-num[ind], num);
    }
    
    return min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    
    int ans =  fun(n-1, x, num);

    if (ans >= 1e9) {
        return -1;
    }
    return ans;
}