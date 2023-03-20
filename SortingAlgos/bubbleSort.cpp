#include <iostream>
using namespace std;


void bubbleSort(int arr[], int l, int r) {
  // int n = r-l+1;
  int count = 0;
  
  while (count < r-1) {
    for (int i = l; i < r - count; i++) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
      }
    }
    count++;
  }
  
}

void printArr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  std::cout << "Hello World!\n";
  int arr[9] = {7, 6, 5, 4, 2, 3, 8, 2, 1};
  int l = 2;
  int r = 6 ;

  bubbleSort(arr, l, r);

  printArr(arr, 9);

  return 0;
}