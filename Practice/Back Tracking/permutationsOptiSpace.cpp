#include <bits/stdc++.h>
using namespace std;

void printAns(vector<vector<char>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

void printPermutations(vector<char> &vec, int ind, vector<vector<char>> &ans) {
    // BASE CASE 
    if (ind == vec.size()) {
        ans.push_back(vec);
        return;
    }
    
    for (int i = ind; i < vec.size(); i++) {
        swap(vec[ind], vec[i]);
        printPermutations(vec, ind+1, ans);
        swap(vec[ind], vec[i]);
    }
}

int main () {
    int n;
    cin >> n;
    vector<char> vec(n);
    for (int i = 0; i < n; i++) {
        cin>> vec[i];
    }

    vector<vector<char>> ans;

    printPermutations(vec, 0, ans);

    return 0;
}