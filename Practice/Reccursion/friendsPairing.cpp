// Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired up only once. Find out the total numbers of ways in which friends can reamin sigle or can paired up


#include<bits/stdc++.h>
using namespace std;

int pairingFriends(int n) {
    // Base case 
    if (n == 1 || n == 2) {
        return n;
    } 

    // single 
    int fnm1 = pairingFriends(n-1);

    // paired up
    int fnm2 = pairingFriends(n-2);

    int totalWays = fnm1 + ((n-1) * fnm2);

    return totalWays;
}


int main () {
    int n;
    cin >> n;

    cout << pairingFriends(n) << " ";

    return 0;
}