#include<bits/stdc++.h>
using namespace std;

void printVector(vector<char> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printSubsets (vector<char> &vec, int i, vector<char> &sub) {
    // base case
    if (i == vec.size()) {
        if (sub.size() == 0) {
            cout << "null";
            return;
        }
        else {
            printVector(sub);
            return;
        } 
    }

    // include 
    sub.push_back(vec[i]);
    printSubsets (vec, i+1,sub);
    sub.pop_back();

    // exclude
    printSubsets (vec, i+1,sub);
}

int main () {  
    int n;
    cin >> n;
    vector<char> vec(n);
    for (int i = 0; i < n; i++) {
        cin>> vec[i];
    }

    vector<char> sub;
    printSubsets(vec, 0, sub);

    return 0;
}