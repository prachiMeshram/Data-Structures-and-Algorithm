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

// class Solution
// {   
//     private:
//     void insertToTail(Node* &cloneHead, Node* &cloneTail, int value) {
//         Node* temp = new Node(value);
        
//         if (cloneHead == NULL) {
//             cloneHead = temp;
//             cloneTail = temp;
//         }
//         else {
//             cloneTail->next = temp;
//             cloneTail = temp;
//         }
//     }
    
//     public:
//     Node *copyList(Node *head)
//     {
//         //Write your code here
//         Node* cloneHead = NULL;
//         Node* cloneTail = NULL;
        
//         // clone the original LL 
//         Node* temp = head;
//         while (temp != NULL) {
//             int value = temp->data; 
//             insertToTail(cloneHead, cloneTail, value);
//             temp = temp->next;
//         }
        
//         unordered_map<Node*, Node*> oldToNew;
        
//         Node* origNode = head;
//         Node* cloneNode = cloneHead;
        
//         while (origNode!=NULL) {
//             oldToNew[origNode] = cloneNode;
//             origNode = origNode->next;
//             cloneNode = cloneNode->next;
//         }
        
//         origNode = head;
//         cloneNode = cloneHead;
        
//         while (origNode != NULL) {
//             cloneNode->arb = oldToNew[origNode->arb];
//             origNode = origNode->next;
//             cloneNode = cloneNode->next;
//         }
        
//         return cloneHead;
//     }

// };

class Solution {
    private:
    
     void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2 add clone nodes btw org nodes
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step3 random pointers copy
        
        
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
                
            }
            temp = temp->next->next;
        }
        
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};