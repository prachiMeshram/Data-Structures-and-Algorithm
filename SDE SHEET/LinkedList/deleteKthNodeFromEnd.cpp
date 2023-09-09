// https://www.codingninjas.com/studio/problems/799912?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// MY SOLUTION
Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if (head == NULL || head->next == NULL) return NULL;
    
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (K == count) {
        return head->next;
    }

    int n = count - K + 1;

    count = 1;
    temp = head;
    Node* prev = NULL;
    while (count != n) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    temp->next = NULL;

    return head;
}

// optimal solution 
Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* start = new Node();
    start->next = head;
    Node* fast = start;
    Node* slow = start;
    
    for (int i = 0; i <= K; i++) {
        fast = fast->next;
    }
    
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    
    return start->next;
}