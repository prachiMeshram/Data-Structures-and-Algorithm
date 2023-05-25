#include<bits/stdc++.h>
using namespace std;

int waysToReach(int n) {

    // base case
    if (n == 1 || n == 0) {
        return 1;
    }

    return waysToReach(n-1) + waysToReach(n-2);
}

int main () {
    int n;
    cin >> n;

    cout <<  waysToReach(n) << " ";

    return 0;
}