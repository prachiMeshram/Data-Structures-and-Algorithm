// https://www.codingninjas.com/studio/problems/795152?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

class Stack {
	// Define the data members.
    queue<int> q1, q2;
    int size;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        size = q2.size();
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if (q2.empty()) {
            return true;
        }
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        // Implement the pop() function.
        if (!q2.empty()) {
            int val = q2.front();
            q2.pop();
            return val; 
        }

        return -1;
    }

    int top() {
        // Implement the top() function.
        if (!q2.empty()) {
            return q2.front();
        }
        return -1;
    }
};