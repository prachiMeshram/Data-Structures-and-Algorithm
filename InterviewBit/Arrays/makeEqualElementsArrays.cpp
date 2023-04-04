#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &A, int B) {
    int min =INT_MAX;
    int max = INT_MIN;
    
    for (int i=0; i<A.size(); i++){
        if (A[i]<min)
            min = A[i];
        if (A[i]>max) 
            max = A[i];
    }
    int target = max-min;
    if (min == max) 
        return 1;
    if (target != B && target!= 2*B) 
        return 0;
    if (target == B){
        for (int i=0; i<A.size(); i++){
            if (A[i]!= max && A[i]!= min )
                return 0;
        }
    }
    return 1;
}



// bool isPossible(vector<int> &A, int B, int curr, vector<int> &Ptemp, vector<int> &temp) {
//     if (curr == A.size()) {
//         return 1;
//     }
    
//     vector<int> currtemp;
//     currtemp.push_back(A[curr]-B);
//     currtemp.push_back(A[curr]);
//     currtemp.push_back(A[curr]+B);
    
//     int i = 0;
//     int j = 0;
    
//     while (i < 3 && j<3) {
//         if (Ptemp[i]<currtemp[j]) {
//             i++;
//         }
//         else if (Ptemp[i] > currtemp[j]) {
//             j++;
//         }
//         else {
//             temp.push_back(Ptemp[i]);
//         }
//     }
//     if(temp.size() == 0) {
//         return 0;
//     }
//     else {
//         return isPossible(A, B, curr+1, Ptemp, temp);
//     }
    
// }

// int Solution::solve(vector<int> &A, int B) {
    
//     vector<int> Ptemp;
//     temp.push_back(A[0]-B);
//     temp.push_back(A[0]);
//     temp.push_back(A[0]+B);
    
//     int curr = 1;
//     vector<int> temp;
    
//     return isPossible(A, B, curr, Ptemp, temp);
// }
