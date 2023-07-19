#include<bits/stdc++.h>
using namespace std;

void heapify (int i, int size, int arr[]) {
    // built maxheap
    int maxInd = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[maxInd] < arr[left]) {
        maxInd = left;
    }

    if (right < size && arr[maxInd] < arr[right]) {
        maxInd = right;
    }

    if (maxInd != i) {
        swap(arr[maxInd], arr[i]);
        heapify(maxInd, size, arr);
    }
}

void heapSort (int arr[], int n) {
    // sort in ascending order
    // built maxHeap
    
    for (int i = n/2; i >= 0; i--) {
        heapify(i, n, arr);
    }

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(0, i, arr);
    }
}

int main () {
    
    int arr[5] = {5, 4, 3, 2, 1};
    heapSort(arr, 5);
    
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " " ;
    }
    return 0;
}