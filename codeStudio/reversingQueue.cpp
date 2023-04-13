// https://www.codingninjas.com/codestudio/problems/reversing-queue_1170046

#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> q) {
  // Write your code here.

  vector<int> temp;
  queue<int> ans;

  int n = q.size();

  for (int i = 0; i < n; i++) {
      int elem = q.front();
      q.pop();
      temp.push_back(elem);
  }
  int s = 0;
  int e = n-1;
  while (s<=e) {
      swap(temp[s++], temp[e--]);
  }

  for (int i = 0; i < n; i++) {
      ans.push(temp[i]);
  }

  return ans;
}
