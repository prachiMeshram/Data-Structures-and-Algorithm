// print all binary strings of size N without consecutive ones

#include<bits/stdc++.h>
using namespace std;

void binaryStings(int n, string newStr, int lastNum) {
    // Base case 
    if (n == 0) {
        cout << newStr << endl;
        return;
    } 

    binaryStings(n-1, newStr + '0', 0);

    if (lastNum == 0) {
        binaryStings(n-1, newStr + '1', 1);
    }

}


int main () {
    int n;
    cin >> n;
    string newStr = "";
    binaryStings(n, newStr, 0);

    return 0;
}