// https://www.codingninjas.com/codestudio/problem-details/third-greatest-element_1095642


#include <bits/stdc++.h> 
using namespace std;

int findThirdLagrest(vector < int > & arr) {
  // Write your code here.
  sort(arr.begin(), arr.end(), greater<int>());

  return arr[2];
}