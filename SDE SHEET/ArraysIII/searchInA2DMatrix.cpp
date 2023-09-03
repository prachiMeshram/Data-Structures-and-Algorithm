// https://www.codingninjas.com/studio/problems/search-in-a-2d-matrix_980531?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// my solution
bool searchMatrix(vector<vector<int>>& mat, int target) {   
    int n = mat.size();
    int m = mat[0].size();

    int s = 0;
    int e = n*m - 1;
    int mid = s + (e-s)/2;

    while (s <= e) {
        if (mat[mid/m][mid%m] == target) {
            return true;
        }
        else if (mat[mid/m][mid%m]< target) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }

    return false;
}