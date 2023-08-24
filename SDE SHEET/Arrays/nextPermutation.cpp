// https://www.codingninjas.com/studio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int s = permutation.size();
    
    int ind = -1;

    for (int i = s-2; i >= 0; i--) {
        if (permutation[i] < permutation[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    
    for (int i = s-1; i > ind; i--) {
        if (permutation[i] > permutation[ind]) {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }

    reverse(permutation.begin()+ind+1, permutation.end());

    return permutation;
}