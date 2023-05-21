#include<bits/stdc++.h>
using namespace std;

int addOneToInt(int a) {
    a = -(~a);

    return a;
}
int main () {
    int a;
    cin>> a;

    cout << addOneToInt(a);

    return 0;
}

