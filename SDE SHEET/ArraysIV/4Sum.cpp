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

// optimal sol
#include<bits/stdc++.h>

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while (k < l) {
                long long sum = nums[i] + nums[j];
                sum += nums[k] + nums[l];
                if ( sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (nums[k] != nums[k-1]) k++;
                    while (nums[l] != nums[l+1]) l--;
                }
                else if ( sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }
    
    return ans;
}