#include<bits/stdc++.h>
using namespace std;

bool checkSortArray(int index, int arr[], int size) {
    // base case 
    if (index == size-1) {
        return true;
    }

    if (arr[index] > arr[index+1]) {
        return false;
    }
    return checkSortArray(index + 1, arr, size);
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 11, 7, 8, 9};

    cout << checkSortArray(0, arr, 9) << " ";
    return 0;
}