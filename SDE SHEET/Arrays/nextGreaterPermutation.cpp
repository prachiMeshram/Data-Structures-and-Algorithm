// https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n = A.size();
    int ind = -1;
    for (int i = n-2; i >= 0; i--) {
        if(A[i] < A[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    for (int i = n-1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }
    reverse(A.begin() + ind + 1, A.end());
    return A;
}