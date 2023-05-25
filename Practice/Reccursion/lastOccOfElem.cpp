#include<bits/stdc++.h>
using namespace std;

int firstOccu(int index, int arr[], int key) {
    // base case 
    if (index < 0) {
        return -1;
    }

    if (arr[index] == key) {
        return index;
    }

    firstOccu (index - 1, arr, key);
}

int main () {
    int arr[] = {1, 2, 11, 4, 5, 11, 7, 8, 10};
    int k;
    cin >> k;
    int size = 9;
    cout << firstOccu(size-1, arr, k) << " ";
    return 0;
}