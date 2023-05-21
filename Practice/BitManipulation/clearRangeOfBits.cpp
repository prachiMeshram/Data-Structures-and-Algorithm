#include<bits/stdc++.h>
using namespace std;

int clearRangeOfBits(int n, int i, int j) {
    int a = ( (~0)<<(j+1) );
    int b = (1<<i) - 1;
    int bitMask = a | b;
    return n & bitMask;
}

int main () {
    int n;
    cin>> n;

    int i;
    cin>> i;

    int j;
    cin>> j;
    
    cout << clearRangeOfBits(n, i, j);

    return 0;
}

