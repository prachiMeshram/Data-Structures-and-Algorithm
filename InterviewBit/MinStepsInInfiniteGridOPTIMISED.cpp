#include <iostream>
#include <vector>
using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int ans = 0; 
    int n = A.size();
    
    for (int i = 1; i < n; i++) {
        ans += (max(abs(A[i]-A[i-1]), abs(B[i]-B[i-1])));
    }
    return ans;
}
