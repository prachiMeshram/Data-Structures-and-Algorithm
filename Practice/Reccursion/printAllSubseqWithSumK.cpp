#include <bits/stdc++.h>
using namespace std;

void printAllSubseqWithSumK(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    // base case 
    
    if (ind == n) {
        if (s == sum) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // include
    
    ds.push_back(arr[ind]);
    s += arr[ind];

    printAllSubseqWithSumK(ind+1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    // exclude
    printAllSubseqWithSumK(ind+1, ds, s, sum, arr, n);
}

int main () {
    int arr[] = {1, 2, 3};
    int n = 3;
    int sum = 2;

    vector<int> ds;

    printAllSubseqWithSumK(0, ds, 0, sum, arr, n);
    return 0;
}