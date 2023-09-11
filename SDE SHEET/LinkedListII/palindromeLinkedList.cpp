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