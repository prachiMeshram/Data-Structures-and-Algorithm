#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// void printAns(vector<vector<int>> &ans) {
//     for (int i = 0; i < ans.size(); i++) {
//         printVector(ans[i]);
//     }
// }

void printPermutations(vector<int> &arr, vector<int> &ds, int map[]) {
    // BASE CASE 
    if (ds.size() == arr.size()) {
        printVector(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (map[i] != 1) {
            ds.push_back(arr[i]);
            map[i] = 1;
            printPermutations(arr, ds, map);
            map[i] = 0;
            ds.pop_back();
        }
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
    }

    vector<int> ds;
    // vector<vector<int>> ans;
    int map[n];
    for (int i = 0; i < n; i++) {
        map[i] = 0;
    }

    printPermutations(arr, ds, map);

    return 0;
}