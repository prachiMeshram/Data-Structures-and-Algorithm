#include<bits/stdc++.h>
using namespace std;

void swapTwoNums(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}
int main () {
    int a;
    cin>> a;
    int b;
    cin>> b;
    swapTwoNums(a, b);
    cout << a << " " << b;

    return 0;
}

