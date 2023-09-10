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
