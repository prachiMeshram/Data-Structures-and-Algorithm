#include<bits/stdc++.h>

using namespace std;


class Heap {
    vector<int> arr;

public:
    void insert(int data) {
        arr.push_back(data);

        int x = arr.size() - 1;
        int par = (x - 1) / 2;

        while (arr[x] < arr[par]) { 
            swap(arr[x], arr[par]);
            x = par;
            par = (x - 1) / 2;
        }

        // for MAX HEAP
        // while (arr[x] > arr[par]) { 
        //     swap(arr[x], arr[par]);
        //     x = par;
        //     par = (x - 1) / 2;
        // }
    }
    int peek () {
        return arr.front();
    }

    void heapify (int i) {
        int minInd = i; // use MaxInd instead
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < arr.size() && arr[minInd] > arr[left]) {
            minInd = left;
        }

        if (right < arr.size() && arr[minInd] > arr[right]) {
            minInd = right;
        }

        // FOR MAX HEAP
        // if (left < arr.size() && arr[minInd] < arr[left]) {
        //     minInd = left;
        // }

        // if (right < arr.size() && arr[minInd] < arr[right]) {
        //     minInd = right;
        // }

        if (minInd != i) {
            swap(arr[minInd], arr[i]);
            heapify(minInd);
        }
    } 

    int remove () {
        int n = arr.size();
        int data = arr[0];

        // swap first and last elem
        swap (arr[0], arr[n-1]);

        // delete last
        arr.erase(arr.begin() + n-1);

        // heapify root
        heapify(0);

        return data;
    }

    bool isEmpty() {
        return arr.size() == 0;
    }
};

int main(){
    Heap h;
    h.insert(3);
    h.insert(4);
    h.insert(1);
    h.insert(5);

    while (!h.isEmpty()) {
        cout << h.peek() << endl;
        h.remove();
    }
    
    return 0;
}