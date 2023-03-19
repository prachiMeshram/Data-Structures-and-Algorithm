#include <iostream>
using namespace std;

void insertionSort (int arr[], int size) {
  
  int i, j, key;
  
  for (int i = 1; i < size; i++) {
    key = arr[i];
    j = i-1;
    while (j>=0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void printArr (int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " " ;
  }
}

int main() {
  std::cout << "Hello World!\n";
  int arr[7] = {7,6,5,4,3,2,1};

  insertionSort (arr, 7);
  printArr(arr, 7);
  return 0;
}