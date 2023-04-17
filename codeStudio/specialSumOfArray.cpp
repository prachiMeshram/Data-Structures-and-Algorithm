// https://www.codingninjas.com/codestudio/problems/special-sum-of-array_893340

#include <bits/stdc++.h> 
using namespace std; 

int specialSum(vector<int>& arr, int n){
    // Write your code here. 

    if (n == 1) {
        return arr[0]; 
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if (sum == 0) {
        return 0;
    }

    vector<int> temp;

    while (sum!=0){
        int digit = sum%10;
        temp.push_back(digit);
        sum = sum/10;
    }

    return specialSum(temp, temp.size());
}