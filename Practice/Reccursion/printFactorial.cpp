#include<bits/stdc++.h>
using namespace std;

int printFac(int n) {
    // base case 
    if ( n == 1) {
        return 1;
    }

    return n * printFac(n-1);
}

int main () {
    int n ;
    cin >> n;

    cout << printFac(n) << " ";
    return 0;
}