// https://practice.geeksforgeeks.org/problems/square-pattern/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printSquare(int n) {
        // code here
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};
