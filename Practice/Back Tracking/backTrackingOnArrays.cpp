#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void changeArray (vector<int> &v, int i) {
    // base case
    if (i == v.size()) {
        printArray(v);
        return;
    }

    v[i] = i+1;
    changeArray(v, i+1);
    v[i] += -2;
}

int main () {  
    int n;
    cin >> n;
    vector<int> vec(n);

    changeArray(vec, 0);
    printArray(vec);

    return 0;
}