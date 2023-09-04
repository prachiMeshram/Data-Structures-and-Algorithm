// https://www.codingninjas.com/studio/problems/4sum_5713771?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

// using 3 loops and set data structures
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            set<long long> hashset;
            for (int k = j+1; k < n; k++) {

                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}