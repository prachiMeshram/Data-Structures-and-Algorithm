#include<iostream>
#include<vector>
using namespace std;

int perfectPeak(vector<int> &A) {
    
    int temp[A.size()];
    temp[A.size()-1] = A[A.size()-1];
    
    for(int i = A.size()-2; i>=0; i--) {
        temp[i] = min(A[i], temp[i+1]);
    }
    
    int maxi = A[0];
    
    for(int i = 1; i < A.size() - 1; i++) {
        if (A[i] > maxi) {
            maxi = A[i];
            if (temp[i+1] > A[i]) {
                return 1;
            }
        }
    }
    
    return 0;
}
