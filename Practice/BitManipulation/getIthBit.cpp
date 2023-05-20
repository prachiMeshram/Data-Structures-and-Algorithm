#include<bits/stdc++.h>
using namespace std;

int getIthBit(int n, int i) {
    int bitMask = 1 << i;

    if (n & bitMask == 0) {
        return 0;
    }
    else {
        return 1;
    }
}
int main () {
    int n;
    cout << "enter number: "<< endl;
    cin>> n;

    int i;
    cout << "enter position: " << endl;
    cin>> i;
    
    cout << i << "th Bit is: "  << getIthBit(n, i);

    return 0;
}