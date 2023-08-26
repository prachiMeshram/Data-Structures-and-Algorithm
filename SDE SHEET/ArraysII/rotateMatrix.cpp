// https://www.codingninjas.com/studio/problems/981260?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top = 0;
    int right= m-1;
    int left = 0;
    int bottom = n-1;

    while (top < bottom && left < right) {
        int temp = mat[top][left];
        
        for (int col = left+1; col <= right; col++) {
            int k = mat[top][col];
            mat[top][col] = temp;
            temp = k;
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            int k = mat[row][right];
            mat[row][right] = temp;
            temp = k;
        }
        right--;

        for (int col = right; col >= left; col--) {
            int k = mat[bottom][col];
            mat[bottom][col] = temp;
            temp = k;
        }
        bottom--;

        for (int row = bottom; row >= top; row--) {
            int k = mat[row][left];
            mat[row][left] = temp;
            temp = k;
        }
        left++;
        
        mat[top-1][left-1] = temp;
    }
}