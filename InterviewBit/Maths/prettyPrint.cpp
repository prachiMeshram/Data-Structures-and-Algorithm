// https://www.interviewbit.com/problems/prettyprint/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > prettyPrint(int A) {
    int n = (2*A)-1;
    
    vector<vector<int>> ans( n , vector<int> (n, 0));
    
    int count = 0;
    int total = ((2*A)-1) * ((2*A)-1);
    int temp = A;
    
    int sR=  0;
    int eR = n-1;
    int sC = 0;
    int eC = n-1;
    while (count < total) {
        
        // start row
        for (int j = sC; j <= eC; j++) {
            ans[sR][j] = temp-sC;
            count++;
        }
        sR++;
        // end col
        for (int i = sR; i <= eR; i++) {
            ans[i][eC] = temp-sC;
            count++;
        }
        eC--;
        // end row
        for (int j = eC; j >= sC; j--) {
            ans[eR][j] = temp-sC;
            count++;
        }
        eR--;
        // start col
        for (int i = eR; i >= sR; i--) {
            ans[i][sC] = temp-sC;
            count++;
        }
        sC++;
    }
    
    return ans;
}
