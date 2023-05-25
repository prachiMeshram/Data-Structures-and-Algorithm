#include<bits/stdc++.h>
using namespace std;

int power2(int a, int b) {
    // base case 
    if (b == 0) {
        return 1;
    }

    int halfPower = power2(a, b/2);
    // int halfPowSq = power2(a, b/2) * power2(a, b/2); // this will increase TC
    int halfPowSq = halfPower*halfPower;

    if (b & 1 == 1) {
        halfPowSq = a * halfPowSq;
    }

    return halfPowSq;
}

int power1(int a, int b) {
    // base case 
    if (b == 0) {
        return 1;
    }
    
    return a * power1(a,b-1);
}

int main () {
    int a, b;
    cin >> a >> b;

    cout << power2(a,b) << " ";
    return 0;
}