#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
  int pi = arr[r];

  int i = l - 1;

  for (int j = l; j < r; j++) {

    if (arr[j] < pi) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[r]);

  return i + 1;
}

void quickSort(int arr[], int l, int r) {

  if (l < r) {
    int pivot = partition(arr, l, r);

    quickSort(arr, l, pivot - 1);

    quickSort(arr, pivot + 1, r);
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

  quickSort(arr, l, r);

  printArr(arr, 9);

  return 0;
}