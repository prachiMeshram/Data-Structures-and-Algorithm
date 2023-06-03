// https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb

#include <bits/stdc++.h> 
class TwoStack {
    int size;
    int* arr;
    int top1;
    int top2; 

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
        // else {
        //     cout << "stack overflow" << endl;
        // }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if (top2-top1 > 1) {
            top2--;
            arr[top2] = num;
        }
        // else {
        //     cout << "stack overflow" << endl;
        // }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if (top1 >= 0) {
            int value = arr[top1];
            top1--;
            return value;
        }
        else {
            return -1;
        }
        // else {
        //     cout << "stack is empty" << endl
        // }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if (top2 < size) {
            int value = arr[top2];
            top2++;
            return value;
        }
        else {
            return -1;
        }
        // else {
        //     cout << "stack is empty" << endl
        // }
    }
};
