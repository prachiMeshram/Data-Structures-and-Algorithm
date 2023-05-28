#include<bits/stdc++.h>
using namespace std;

int gridWays(int i, int j, int n, int m) {
    // BASE CASE
    if (i == n-1 && j == m-1) {
        return 1;
    }
    if (i >= n || j >=m) {
        return 0;
    }

    return gridWays(i+1, j, n, m) + gridWays(i, j+1, n, m);
}

int main () {
    int n, m;
    cin >> n >> m;

    cout << gridWays(0, 0, n, m) << " ";

    return 0;
}