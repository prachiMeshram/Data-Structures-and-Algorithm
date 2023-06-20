// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n) {
  // Write your code here.
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  int k = sum;
  
  vector<bool> prev(k+1, false);
  prev[0] = true;
  if (arr[0] <= k) {
    prev[arr[0]] = true;
  }

  vector<bool> curr(k+1, false);

  for (int ind = 1; ind < n; ind++) {
	curr[0] = true;  
    for (int target = 1; target <= k; target++) {
      bool notTake = prev[target];
      bool take = false;
      if (arr[ind] <= target) {
        take = prev[target - arr[ind]];
      }

      curr[target] = take || notTake;
    }
	prev = curr;
  }

  // dp[n-1][col...]
  int mini = 1e9;

  for (int s1 = 0; s1 <= k / 2; s1++) {
    if (prev[s1] == true) {
		mini = min (mini, abs((sum-s1) - s1));
	}
  }

  return mini;
}
