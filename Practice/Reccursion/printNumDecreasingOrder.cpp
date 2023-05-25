#include<bits/stdc++.h>
using namespace std;

void printNumDecOrder (int n) {
    // base case
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printNumDecOrder (n-1);
}

int main () {

    int n;
    cin >> n;

    printNumDecOrder (n);

    return 0;
}