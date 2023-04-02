// https://www.interviewbit.com/problems/set-matrix-zeros/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int rows = A.size();
    int cols = A[0].size();
    
    vector<int> zeroR(rows, 1);
    vector<int> zeroC(cols, 1);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 0) {
                zeroR[i] = 0;
                zeroC[j] = 0;
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <cols; j++) {
            if ((zeroC[j] && zeroR[i]) == 0) {
                A[i][j] = 0;
            }
        }
    }
    
    
}
