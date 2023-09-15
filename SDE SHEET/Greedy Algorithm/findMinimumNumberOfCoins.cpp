// https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

vector<int> MinimumCoins(int n)
{
    // Write your code here
    int num = n;
    vector<int> ans;
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < coins.size(); i++) {
        while (num >= coins[i]) {
            ans.push_back(coins[i]);
            num -= coins[i]; 
        }
    }
    return ans;
}