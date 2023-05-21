#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
   return (n & (n-1) == 0);
}

int main () {
    int Num;
    cin>> Num;
    
    cout << isPowerOfTwo(Num);

    return 0;
}


