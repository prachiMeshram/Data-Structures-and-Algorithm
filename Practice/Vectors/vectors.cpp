#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    vector<int> :: iterator it;
    for (it = v.begin(); it!=v.end(); it++) {
        cout << *it << " ";
    } // 1 2 3

    for (auto elem:v) {
        cout << elem << " ";
    } // 1 2 3 
    
    v.pop_back(); // 1 2 

    vector<int> v2 (3,50);

    swap(v, v2);
    for (auto elem: v) {
        cout << elem << " ";
    }

    for (auto elem: v2) {
        cout << elem << " ";
    }

    sort(v.begin(), v.end());

    return 0;
}