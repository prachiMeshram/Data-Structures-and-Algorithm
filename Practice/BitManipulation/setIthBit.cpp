#include<bits/stdc++.h>
using namespace std;

int setIthBit(int n, int i) {
    int bitMask = 1 << i;

    return n | bitMask;
}
int main () {
    int Num;
    cin>> Num;
    int i;
    cin>> i;
    
    cout << setIthBit(Num, i);

    return 0;
}

