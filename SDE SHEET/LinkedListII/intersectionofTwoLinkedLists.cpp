// https://www.codingninjas.com/studio/problems/630457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// BRUTE FORCE
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *curr1 = firstHead;

    while (curr1 != NULL)
    {
        Node *curr2 = secondHead;
        while (curr2 != NULL)
        {
            if (curr1 == curr2)
            {
                return curr1;
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return NULL;
}

// using hashing 
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_set<Node*> st;
    Node* temp = firstHead;
    
    while (temp != NULL) {
        st.insert(temp);
        temp = temp->next;
    }
    
    temp = secondHead;
    while (temp != NULL) {
        if (st.find(temp) != st.end()) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}


// USING DIFFERENCE
int getDiff(Node *head1, Node* head2) {
    int n1 = 0, n2 = 0;
    while (head1!=NULL || head2!=NULL) {
        if (head1!=NULL) {
            n1++;
            head1 = head1->next;
        }
        if (head2!=NULL) {
            n2++;
            head2 = head2->next;
        }
    }
    return n1-n2;
}
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* a = firstHead;
    Node* b = secondHead;
    
    int diff = getDiff(a, b);
    
    if (diff < 0) {
        while (diff != 0) {
            b = b->next;
            diff++;
        }
    }
    else {
        while (diff) {
            a = a->next;
            diff--;
        }
    }
    
    while (a != b) {
        a = a->next;
        b = b->next;
    } 
    return a;
}

// OPTIMAL APPROACH
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* a = firstHead;
    Node* b = secondHead;
    
    while (a != b) {
        a = a==NULL ? secondHead : a->next;
        b = b==NULL ? firstHead : b->next;
    }
    return a;
}


