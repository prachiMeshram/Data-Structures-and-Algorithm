
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e, int mid) {

    int size = e-s+1;
    int* temp = new int[size];
    
    int i = s;
    int j = mid+1;
    int k = 0;
    while (i<=mid && j<=e) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= e) {
        temp[k++] = arr[j++];
    }
    // copy temp to original array
    
    for (int k = 0, i = s; k < size; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int s, int e) {
    // base case 
    if (s>=e) {
        return;
    }

    int mid = (s + (e-s)/2);
    // left half
    mergeSort(arr, s, mid);
    // right half
    mergeSort(arr, mid+1, e);
    // merge two sorted arrays
    merge(arr, s, e, mid);
}


int main () {
    
    int arr[] = {6, 11, 9, 5, 2, 8};

    mergeSort(arr, 0, 6);
    
    for (int i = 0; i < 6; i++) {
        cout<<arr[i] << " ";
    }
    return 0;
}