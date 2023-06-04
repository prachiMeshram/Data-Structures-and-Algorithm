// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0?source=youtube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio 

#include <bits/stdc++.h> 
using namespace std;

void solve (stack<int>& myStack, int x, int size) {
    if (size == 0) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    solve(myStack, x, size-1);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    int size = myStack.size();

    solve(myStack, x, size);

    return myStack;

}
