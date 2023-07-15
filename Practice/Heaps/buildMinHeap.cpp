// https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

class heap {
    public:
    int arr[100];
    int size = 0;
    
    heap () {
        arr[0] = -1;
        size = 0;
    }

    void insert (int val) {
        size += 1;
        int index = size;
        arr[index] = val; 

        while (index > 1) {
            
            int parent = index/2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    // delete root node
    void deleteFromHeap() {
        if (size == 0) {
            cout << " nothing to delete" << endl;
            return;
        }
        // step 1: swap last and first elem
        swap(arr[1], arr[size]);
        // step 2: remove last elem
        size--;
        // take root node to its correct position
        int i = 1; 
        while (i < size) {
            int left = 2*i;
            int right = 2*i + 1;

            if (left < size && arr[left] > arr[i]) {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if (right < size && arr[right] > arr[i]) {
                swap(arr[right], arr[i]);
                i = right;
            }
            else {
                return;
            }
        }
    }

    void print() {
        
        int ind = 1;
        while (ind < size) {
            cout << arr[ind] << " ";
            ind++;
        }
        cout << endl;
    }
};

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

int main () {
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deleteFromHeap();
    h.print();

    return 0;
}
