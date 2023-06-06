// https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h> 
using namespace std;

class CircularQueue{
    int *arr;
    int qfront;
    int rear;
    int size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.

        // check arr is full
        if ((qfront == 0 && rear == size-1) || (rear == (qfront-1)%(size-1)) ) {
            return false;
        }
        else if (qfront == -1) { // for single element
            qfront = rear = 0;
        }
        else if (rear == size-1 && qfront != 0){
            rear = 0; // maintain cyclic nature
        }
        else { 
            rear++; // normal flow
        }

        // push inside the queue
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.

        // check for empty queue
        if (qfront == -1) {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        
        if (qfront == rear) { // only one elem present
            qfront = rear = -1;
        }
        else if (qfront == size-1) { // cyclic nature
            qfront = 0;
        }
        else {
            qfront++;
        }
        return ans;
    }
};