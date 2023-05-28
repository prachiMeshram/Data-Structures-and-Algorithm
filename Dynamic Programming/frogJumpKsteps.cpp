#include <bits/stdc++.h>
using namespace std;

// int frogKjumps(int i, vector<int> &heights, vector<int> &dp, int k) {
//     // base case 
//     if (i == 0) {
//         return 0;
//     }
//     if (dp[i] != -1) {
//         return dp[i];
//     }

//     int minSteps = INT_MAX;

//     for (int j = 1; j <= k; j++) {
//         if (i - j >= 0) {
//             int jumps = frogKjumps(i - j, heights, dp, k) + abs(heights[i] - heights[i - j]);
//             minSteps = min(minSteps, jumps);
//         }
//     }
//     return dp[i] = minSteps;
// }

// tabulation approach
int frogKjumpsKsteps(int n, vector<int> &heights, vector<int> &dp, int k) {
    dp[0] = 0;
    
    for (int i = 1; i < n; i++) {

        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i-j >= 0) {
                int jumps = dp[i-j] + abs(heights[i] - heights[i - j]);
                minSteps = min(jumps, minSteps);
            }
        }
        dp[i] = minSteps;
    }

    return  dp[n-1];
}

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    int k = 2;
    vector<int> dp(n, -1);
    // cout << frogKjumps(n - 1, heights, dp, k);
    cout << frogKjumpsKsteps(n, heights, dp, k);

    return 0;
}
