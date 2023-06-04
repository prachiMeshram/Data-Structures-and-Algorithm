// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
using namespace std;

void insertAtBottom(stack<int>& myStack, int x) {
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    insertAtBottom(myStack, x);

    myStack.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    // base case 
    if (stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack, num);

}