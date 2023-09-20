// https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// Stack class.
class Stack {
    int size;
    int *arr;
    int t;
public:
    
    Stack(int capacity) {
        // Write your code here.
        t = -1;
        size = capacity;
        arr = new int[capacity];
    }

    void push(int num) {
        // Write your code here.
        if (!isFull()) {
            arr[++t] = num;
        }  
    }

    int pop() {
        // Write your code here.
        if (t != -1) {
            int val = arr[t];
            t--;
            return val;
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if (t != -1) {
            return arr[t];
        }
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return (t == -1) ? 1 : 0;
    }
    
    int isFull() {
        // Write your code here.
        return (t+1 == size) ? 1 : 0;
    }
    
};
