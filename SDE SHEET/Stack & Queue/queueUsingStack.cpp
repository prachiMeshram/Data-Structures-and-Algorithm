// https://www.codingninjas.com/studio/problems/799482?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// Using two Stacks where push operation is O(1)

class Queue {
    // Define the data members(if any) here.
    stack<int> input, output;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty()) return -1;
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty()) return -1;
        return output.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if (input.empty() && output.empty()) return true;
        return false;
    }
};


// Using two Stacks where push operation is O(N)
class Queue {
    // Define the data members(if any) here.
    stack<int> input;
    stack<int> output;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
            
        }
        input.push(val);
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (input.empty()) return -1;
        
        int val = input.top();
        input.pop();
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if (input.empty()) return -1;
    
        return input.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if (input.size() == 0) {
            return true;
        }
        return false;
    }
};