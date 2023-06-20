// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

// recursion
bool f(int i, int k, vector<int> &arr)
{
  if (k == 0)
  {
    return true;
  }
  if (i == 0)
  {
    return (arr[0] == k);
  }

  // not take
  bool notTake = f(i - 1, k, arr);
  // take
  bool take = false;
  if (arr[i] <= k)
  {
    take = f(i - 1, k - arr[i], arr);
  }

  return notTake | take;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // Write your code here.

  return f(n - 1, k, arr);
}

// recursion using DP
bool f(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
  if (k == 0)
  {
    return true;
  }
  if (i == 0)
  {
    return (arr[0] == k);
  }

  if (dp[i][k] != -1)
  {
    return dp[i][k];
  }

  // not take
  bool notTake = f(i - 1, k, arr, dp);
  // take
  bool take = false;
  if (arr[i] <= k)
  {
    take = f(i - 1, k - arr[i], arr, dp);
  }

  return dp[i][k] = notTake | take;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // Write your code here.
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return f(n - 1, k, arr, dp);
}

// tabulation

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // Write your code here.
  vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }

  if (arr[0] <= k)
  {
    dp[0][arr[0]] = true;
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int target = 1; target <= k; target++)
    {
      // not take
      bool notTake = dp[ind - 1][target];
      // take
      bool take = false;
      if (arr[ind] <= target)
      {
        take = dp[ind - 1][target - arr[ind]];
      }

      dp[ind][target] = take || notTake;
    }
  }

  return dp[n - 1][k];
}

// space optimisation

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<bool> prev(k + 1, false);

  prev[0] = true;

  if (arr[0] <= k)
    prev[arr[0]] = true;

  vector<bool> cur(k + 1, false);

  for (int ind = 1; ind < n; ind++)
  {
    cur[0] = true;
    for (int target = 1; target <= k; target++)
    {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  return prev[k];
}
