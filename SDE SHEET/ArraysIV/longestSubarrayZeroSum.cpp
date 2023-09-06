// https://www.codingninjas.com/studio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

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