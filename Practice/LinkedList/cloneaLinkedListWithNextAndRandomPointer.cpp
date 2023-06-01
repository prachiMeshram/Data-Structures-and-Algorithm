// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{   
    private:
    void insertToTail(Node* &cloneHead, Node* &cloneTail, int value) {
        Node* temp = new Node(value);
        
        if (cloneHead == NULL) {
            cloneHead = temp;
            cloneTail = temp;
        }
        else {
            cloneTail->next = temp;
            cloneTail = temp;
        }
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        // clone the original LL 
        Node* temp = head;
        while (temp != NULL) {
            int value = temp->data; 
            insertToTail(cloneHead, cloneTail, value);
            temp = temp->next;
        }
        
        unordered_map<Node*, Node*> oldToNew;
        
        Node* origNode = head;
        Node* cloneNode = cloneHead;
        
        while (origNode!=NULL) {
            oldToNew[origNode] = cloneNode;
            origNode = origNode->next;
            cloneNode = cloneNode->next;
        }
        
        origNode = head;
        cloneNode = cloneHead;
        
        while (origNode != NULL) {
            cloneNode->arb = oldToNew[origNode->arb];
            origNode = origNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }

};