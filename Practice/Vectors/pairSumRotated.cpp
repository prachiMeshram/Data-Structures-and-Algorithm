#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int> &v, int k) {
    int n = v.size();

    int breakpoint = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            breakpoint = i;
            break;
        }
    }

    int s = breakpoint+1;
    int e = breakpoint;

    while (s < e) {
        // CASE 1
       if (v[s] + v[e] == k) {
           cout << v[s] << " " << v[e] << " ";
           return;
       }

        // CASE 2
       if (v[s] + v[e] < k) {
           s = (s + 1) % n;
       }
       else {
        // case 3
           e = (e + n - 1) % n;
       }
    }
}

int main () {
    int k;
    cin >> k;
    vector<int> v = {11, 15, 6,8, 9, 10}; // SORTED AND ROTATED

    pairSum(v, k);

    return 0;
}