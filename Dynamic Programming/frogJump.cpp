#include<bits/stdc++.h>
using namespace std;

// recursion
// int frogJumps(int index, vector<int> &arr) {
//     // base case
//     if (index == 0) {
//         return 0;
//     }

//     // left 
//     int left = frogJumps(index-1, arr) + abs(arr[index] - arr[index-1]);
//     // right
//     int right = INT_MAX;
//     if (index > 1) {
//         right = frogJumps(index - 2, arr) + abs(arr[index] - arr[index-2]);
//     }

//     return min(left, right);

// }

// with DP 
int frogJumps(int index, vector<int> &arr, vector<int> &dp) {
    // base case
    if (index == 0) {
        return 0;
    }
    if (dp[index] != -1) {
        return dp[index];
    }

    // left 
    int left = frogJumps(index-1, arr, dp) + abs(arr[index] - arr[index-1]);
    // right
    int right = INT_MAX;
    if (index > 1) {
        right = frogJumps(index - 2, arr, dp) + abs(arr[index] - arr[index-2]);
    }

    return dp[index] = min(left, right);

}

// int main () {

// // int n;
// // cin >> n;

// vector<int> arr{ 10, 20, 30, 10 };
// // for (int i = 0; i < n; i++) {
// //     cin >> arr[i];
// // }
// int n = arr.size();
// vector<int> dp(n, -1);

// // cout << frogJumps(3, arr) << " ";
// // cout << frogJumps(3, arr, dp) << " ";
// }

// TABULATION APPROACH
// int main () {
//     vector<int> arr{ 10, 20, 30, 10 };
//     int n = arr.size();
//     vector<int> dp(n, -1);
//     dp[0] = 0;
//     for (int i = 1; i < n; i++) {
//         int jumpNM2 = INT_MAX;
//         int jumpNM1 = dp[i-1] + abs(arr[i] - arr[i-1]); 
//         if (i>1) {
//             jumpNM2 = dp[i-2] + abs(arr[i] - arr[i-2]); 
//         }
//         dp[i] = min(jumpNM1, jumpNM2);
//     }
//     cout << dp[n-1];
// }

// SPACE OPTIMIZATION

int main () {
    vector<int> arr{ 10, 20, 30, 10 };
    int n = arr.size();
    int prev1 = 0; 
    int prev2 = 0; 

    for(int i = 1; i < n; i++) {

        int jumpNM1 = prev1 + abs(arr[i] - arr[i-1]);
        int jumpNM2;
        if (i > 1) {
            jumpNM2 = prev2 + abs(arr[i] - arr[i-2]);
        }
        int curr  = min(jumpNM1, jumpNM2);
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
}