// Question Link => https://www.codingninjas.com/codestudio/problems/next-greater-element-i_3651446

#include <bits/stdc++.h> 
using namespace std;

int search(int num, vector<int> &B){
    int m = B.size();

    int index = 0;

    for(int i = 0; i < m; i++){
        if(num == B[i]){
            index = i;
            break;
        }
    }

    for(int i = index + 1; i < m; i++){
        if(num < B[i]){
            return B[i];
        }
    }

    return -1;
}

vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B) {
    // Write your code here.

    vector<int> ans;

    for(int i = 0; i < n; i++){
        ans.push_back(search(A[i], B));
    }

    return ans;
}