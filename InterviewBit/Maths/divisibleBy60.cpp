// https://www.interviewbit.com/problems/divisible-by-60/

#include<bits/stdc++.h>
using namespace std;

int divisibleBy60(vector<int> &A) {
    if (A[0] == 0) {
        return 1;
    }
    
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    if (sum%3!=0) {
        return 0;
    }
    
    bool isZero = false; 
    bool isFour = false;
    for(int i = 0; i < A.size(); i++) {
        if(A[i]==0) {
            isZero = true;
        }
        if (A[i] == 4 || A[i] == 2 || A[i] == 6) {
            isFour = true;
        }
        if (isFour == true && isZero == true) {
            break;
        }
    }
    if (sum%3==0 && isFour== true && isZero==true) {
        return 1;
    }
    return 0;
}
