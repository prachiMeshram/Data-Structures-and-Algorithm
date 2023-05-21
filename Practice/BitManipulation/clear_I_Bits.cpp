#include<bits/stdc++.h>
using namespace std;



int clearIBits(int n, int i) {
    int bitMask = (~0) << i;
    return n&bitMask;
}

int main () {
    int Num;
    cin>> Num;

    int i;
    cin>> i;
    
    cout << clearIBits(Num, i);

    return 0;
}

