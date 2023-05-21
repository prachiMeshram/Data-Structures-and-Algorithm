#include<bits/stdc++.h>
using namespace std;

int fastExponentiation(int a, int b) {
    int ans = 1;

    while (b != 0) {
        if (b & 1 == 1) {
            ans = ans*a;
        }
        a = a*a;
        b = b>>1;
    }

    return ans;
}
int main () {
    int a;
    cin>> a;
    int b;
    cin>> b;
    
    cout << fastExponentiation(a, b);

    return 0;
}

