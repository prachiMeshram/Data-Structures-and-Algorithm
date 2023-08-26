// https://www.codingninjas.com/studio/problems/981260?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // transpose
         for (int i = 0; i < n; i++) { // check loop condition
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            int s = 0; 
            int e = m-1;
            while (s < e) {
                swap(mat[i][s++], mat[i][e--]);
            }
        }
        return;
    }
};