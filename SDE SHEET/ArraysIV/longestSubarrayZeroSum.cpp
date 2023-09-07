// both positives and negatives
// https://www.codingninjas.com/studio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// only positives
// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n = arr.size();
  int len = 0;

  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = i; j < n; j++) {
      s += arr[j];
      
      if (s == 0) {
        len = max(len, j-i+1);
      }
    }
  }

  return len;
}

// optimal for zeros and negatives 
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n = arr.size();
  map<int, int> prefixSum;
  
  int maxlen = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == 0) {
      maxlen = max(maxlen, i+1);
    }
    int rem = sum;
    if (prefixSum.find(rem) != prefixSum.end()) {
      int len = i - prefixSum[rem];
      maxlen = max(maxlen, len);
    }
    if (prefixSum.find(sum) == prefixSum.end()) {
      prefixSum[sum] = i;
    }
  }
  return maxlen;
}

// optimal code for only positives
int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here
     int n = arr.size();
    int l = 0, r = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while (r < n) {
        while (l <= r && sum > k) {
        sum -= arr[l];
        l++;
        }
        if (sum == k) {
        maxLen = max(maxLen, r-l+1);
        }

        r++;
        if (r < n) sum += arr[r];
    }
    return maxLen;
}