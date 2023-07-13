// https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
void heapify(vector<int> &arr, int i, int n) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, smallest, n);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    // since the array is 0 based indexing leaf node starts from n/2 to n;
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
    return arr;
}
