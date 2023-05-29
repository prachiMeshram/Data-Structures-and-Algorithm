#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int> &v, int k) {
    int s = 0;
    int e = v.size()-1;

    while (s < e) {
       if (v[s] + v[e] == k) {
           cout << v[s] << " " << v[e] << " ";
           return;
       }
       if (v[s] + v[e] < k) {
           s++;
       }
       else {
           e--;
       }
    }
}

int main () {
    int k;
    cin >> k;
    vector<int> v = {1,2,3,4,5,6,7};

    pairSum(v, k);

    return 0;
}