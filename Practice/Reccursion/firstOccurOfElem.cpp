#include<bits/stdc++.h>
using namespace std;

int firstOccu(int index, int arr[], int key, int size) {
    // base case 
    if (index == size-1) {
        return -1;
    }

    if (arr[index] == key) {
        return index;
    }

    firstOccu (index + 1, arr, key, size);
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 11, 7, 8, 11};
    int k;
    cin >> k;
    int size = 9;
    cout << firstOccu(0, arr, k, size) << " ";
    return 0;
}