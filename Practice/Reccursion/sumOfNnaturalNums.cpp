#include<bits/stdc++.h>
using namespace std;

int sumUptoNums(int n) {
    // base case 
    if (n == 1) {
        return n;
    }

    return n + sumUptoNums(n-1);
}

int main () {
    int n;
    cin >> n;

    cout << sumUptoNums(n) << " ";
    return 0;
}