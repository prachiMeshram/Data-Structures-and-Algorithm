#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;

    while (n != 0) {
        if (n & 1) { // check LSB
            count++;
        }
        n = n>>1;
    }

    return count;
}

int main () {
    int Num;
    cin>> Num;
    
    cout << countSetBits(Num);

    return 0;
}

