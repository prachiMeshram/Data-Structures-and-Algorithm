// https://www.codingninjas.com/studio/problems/893028?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// OPTIMAL APPROACH
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int l = i+1;
        int r = n-1;
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == K) {
                vector<int> temp = {arr[i], arr[l], arr[r]};
                ans.push_back(temp);
                l++;
                r--;
                while (arr[l] == arr[l-1]) l++;
                while (arr[r] == arr[r+1]) r--;
            }
            else if (sum < K) {
                l++; 
            }
            else {
                r--;
            }
        }
    }
    
    return ans;
    
}