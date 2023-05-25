#include<bits/stdc++.h>
using namespace std;

// alpha approach
int lastOccurence (int index, int arr[], int key, int n) {
    

    // base case 
    if (index == n) {
        return -1;
    }

    int isFound = lastOccurence(index+1, arr, key, n);

    if (isFound == -1 && arr[index] == key) {
        return index;
    }

    return isFound;
}



// my aproach
int lastOccu(int index, int arr[], int key) {
    // base case 
    if (index < 0) {
        return -1;
    }

    if (arr[index] == key) {
        return index;
    }

    lastOccu (index - 1, arr, key);
}

int main () {
    int arr[] = {1, 2, 11, 4, 5, 11, 7, 8, 10};
    int k;
    cin >> k;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lastOccurence(0, arr, k, n) << " ";
    return 0;
}