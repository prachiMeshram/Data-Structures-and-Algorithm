#include <bits/stdc++.h> 
#include <vector> 
using namespace std;

int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z)
{   
    // Write your code here.

    int i = 0;
    int j = 0;
    int k = 0;

    int x = X.size();
    int y = Y.size();
    int z = Z.size();
    
    int ans = INT_MAX;

    while (i<x && j<y && k<z) {
        int mini = X[i];
        if (Y[j]<mini) {
            mini = Y[j];
        }
        if (Z[k] < mini) {
            mini = Z[k];
        }

        int maxi = X[i];
        if (Y[j]>maxi) {
            maxi = Y[j];
        }
        if (Z[k] > maxi) {
            maxi = Z[k];
        }

        ans = min(ans, abs(maxi-mini));

        if(mini == X[i]){
            i++;
        }
        else if (mini == Y[j]) {
            j++;
        }
        else {
            k++;
        }
    }

    return ans;

    // METHOD I (BRUTE FORCE TLE)

    // vector<int> maxi;

    // for (int i = 0; i < X.size(); i++) {
    //     for (int j = 0; j < Y.size(); j++) {
    //         for (int k = 0; k < Z.size(); k++) {
    //             int tempMax = max(abs(Y[j]-Z[k]), abs(X[i]-Z[k]));
    //             if (tempMax < abs(X[i]-Y[j])) {
    //                 tempMax = abs(X[i]-Y[j]);
    //             }
    //             maxi.push_back(tempMax);
    //         }
    //     }
    // }

    // int ans = INT_MAX;
    // for (int i = 0; i < maxi.size(); i++) {
    //     if (ans > maxi[i]) {
    //         ans = maxi[i];
    //     }
    // }
    // return ans;
}
