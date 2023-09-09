// https://www.codingninjas.com/studio/problems/973250?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

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


Node *findMiddle(Node *head) {
    // Write your code here
    if (head == NULL && head->next == NULL) {
        return head;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL) {
            fast = fast->next;
        }
    }
    
    return slow;
}

