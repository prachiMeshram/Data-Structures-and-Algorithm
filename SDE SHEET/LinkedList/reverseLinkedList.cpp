// https://www.codingninjas.com/studio/problems/799897?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;


    // Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


// ITERATIVE APPROACH
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *forward;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
    }
    
    return prev;
}

// RECURSIVE APPROACH
void solve(LinkedListNode<int>* &nHead, LinkedListNode<int> *curr, LinkedListNode<int> *prev) {
    if (curr == NULL) {
        nHead = prev;
        return;
    }
    LinkedListNode<int> *forward = curr->next;
    solve(nHead, forward, curr);
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    LinkedListNode<int> *nHead = head;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    
    solve(nHead, curr, prev);
    
    return nHead;
}