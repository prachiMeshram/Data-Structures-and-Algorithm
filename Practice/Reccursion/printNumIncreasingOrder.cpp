#include<bits/stdc++.h>
using namespace std;

void printNumsIncreOrder (int num) {
    // base case 
    if (num == 0) {
        return;
    }

    printNumsIncreOrder (num-1);

    cout << num << " ";
}

int main () {
    int num;

    cin >> num;

    printNumsIncreOrder (num);
    return 0;
};