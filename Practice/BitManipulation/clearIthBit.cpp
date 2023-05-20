#include<bits/stdc++.h>
using namespace std;

int clearIthBit(int n, int i) {
    int bitMask = ~(1 << i);

    return n & bitMask;
}
int main () {
    int Num;
    cin>> Num;
    int i;
    cin>> i;
    
    cout << clearIthBit(Num, i);

    return 0;
}

