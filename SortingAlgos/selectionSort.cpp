#include <iostream>
using namespace std;


void selectionSort(int arr[], int l, int r) {

  for (int i = l; i < r; i++) {
    int minIndex = i;
    for (int j = i+1; j<=r; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    } 
    swap (arr[minIndex], arr[i]);
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
  int l = 1;
  int r = 8;

  selectionSort(arr, l, r);

  printArr(arr, 9);

  return 0;
}