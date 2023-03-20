#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
  
  int n1 = mid - l + 1;
  int n2 = r-mid;

  int a[n1], b[n2];
  
  for (int i = 0; i < n1; i++) {
    a[i] = arr[l+i];
  }

  for (int i = 0; i < n2; i++) {
    b[i] = arr[mid+1+i];
  }

  // now merge two arrays
  int i=0;
  int j=0;
  int k=l;
  
  while (i<n1 && j<n2) {
    if (a[i] < b[j]) {
      arr[k++] = a[i++];
    }
    else {
      arr[k++] = b[j++]; 
    }
  }

  while (i < n1) {
    arr[k++] = a[i++];
  }

  while (j<n2) {
    arr[k++] = b[j++];  
  }
  
}

void mergeSort (int arr[], int l, int r) {

  if (l<r) {
    int mid = (l + (r-l)/2);
  
    mergeSort (arr, l, mid);
    mergeSort (arr, mid+1, r);

    merge(arr, l, mid, r);
  }
  return;
}

void printArr (int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " " ;
  }
}

int main() {
  std::cout << "Hello World!\n";
  int arr[9] = {7,6,5,4,2,3, 8, 2,1};
  int l = 0;
  int r = 8;
  
  mergeSort (arr, l, r);
  
  printArr(arr, 9);
  
  return 0;
}