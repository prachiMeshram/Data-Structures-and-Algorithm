// https://www.codingninjas.com/studio/problems/799352?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

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

// brute force
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector<int> v;
    LinkedListNode<int> *temp = head;
    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0;
    int e = v.size()-1;
    while (s <= e) {
        if (v[s] != v[e]) {
            return false;
        }
        s++;
        e--;
    }

    return true;
}

// const space approach
LinkedListNode<int> *reverse(LinkedListNode<int> *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    LinkedListNode<int> *nh = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return nh;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if (head == NULL || head->next == NULL) {
        return true;
    }
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int> *temp = head;
    
    while (slow != NULL) {
        if (temp->data != slow->data) {
            return false;
        }
        temp = temp->next;
        slow = slow->next;
    }
    return true;
}