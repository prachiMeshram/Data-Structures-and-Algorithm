#include<bits/stdc++.h>
using namespace std;

int clearIthBit(int n, int i) {
    int bitMask = ~(1 << i);

    return n & bitMask;
}

int setIthBit(int n, int i) {
    int bitMask = 1 << i;

    return n | bitMask;
}

int updateIthBit(int n, int i, int newBit) {
    n = clearIthBit(n, i);
    int bitMask = newBit<<i;
    return n|bitMask;
}

int main () {
    int Num;
    cin>> Num;

    int i;
    cin>> i;

    int newBit;
    cin>> newBit;
    
    cout << updateIthBit(Num, i, newBit);

    return 0;
}

