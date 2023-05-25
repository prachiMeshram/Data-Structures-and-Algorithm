// TILING PROBLEM 

// Given a "2*n" board and tiles of size "2*1", count the number of ways to tile the given board using the 2*1 tiles.
// (A tile can either be placed horizontally or vertically)

#include<bits/stdc++.h>
using namespace std;

int solveTiling (int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;
    }

    // vertically 
    int fnm1 = solveTiling(n-1);
    // horizontally 
    int fnm2 = solveTiling(n-2);

    int totalWays = fnm1 + fnm2;

    return totalWays;
}

int main () {
    int num;
    cin >> num;
    cout << solveTiling(num)<< " ";
    return 0;
}