// https://www.interviewbit.com/problems/matrix-search/discussion/p/binary-search-use-column-size-to-find-exact-mid-point-in-matrix/385512/763/

#include<bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    
    int rows = A.size();
    int cols = A[0].size();
    
    int s = 0;
    int e = (rows*cols) - 1 ;
    int mid = s + (e-s)/2;
    
    while (s <= e) {
        int r = mid/cols;
        int c = mid%cols;
        if (A[r][c] == B) {
            return 1;
        }
        else if (B < A[r][c]) {
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return 0;
}
