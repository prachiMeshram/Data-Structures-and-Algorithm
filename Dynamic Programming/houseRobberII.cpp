// https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;


long long int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    // optimised SPACE COMPLEXITY

    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++) {

        long long int include = nums[i];
        if (i>1) {
            include += prev2;
        }
        long long int exclude = prev;

        long long int curri = max(include, exclude);
        prev2 = prev;
        prev = curri;
    }

    return prev;

}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    
    vector<int> temp1;
    vector<int> temp2;
    int n = valueInHouse.size();

    if (n == 1) {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++) {
        if (i!=0) {
            temp1.push_back(valueInHouse[i]);
        }
        if (i!=n-1) {
            temp2.push_back(valueInHouse[i]);
        }
    }
    long long int ans = max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    return ans;
}