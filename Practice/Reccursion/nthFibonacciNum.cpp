#include<bits/stdc++.h>
using namespace std;

int nthFibNum (int n) {
    // base case 
    if (n == 1 || n == 0) {
        return n;
    }

    return nthFibNum(n-1) + nthFibNum(n-2);
}

int main () {
    int n;
    cin >> n;

    cout << nthFibNum(n) << " ";
    return 0;
}